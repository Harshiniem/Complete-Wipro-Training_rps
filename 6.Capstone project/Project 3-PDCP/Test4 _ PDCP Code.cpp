// ============================================================
// 5G PDCP Simulator
// Includes:
// 1) PDCP Ciphering & Integrity (TS 38.323 §5.8)
// 2) ROHC Header Compression (TS 38.323 §5.7.4)
// ============================================================

#include <iostream>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

/* ============================================================
   PART 1: PDCP SECURITY (CIPHERING + INTEGRITY)
   ============================================================ */

struct PDCPSecurityParams {
    uint32_t count;        // HFN + SN
    uint8_t bearer;        // Radio bearer ID
    uint8_t direction;     // 0 = UL, 1 = DL
    string cipher_alg;     // NEA0-3
    string integ_alg;      // NIA0-3
};

// Display PDCP Security Processing
void show_security_processing(const PDCPSecurityParams& p,
                              bool is_srb) {

    cout << "Security Parameters:\n";
    cout << "  COUNT: 0x" << hex << p.count << dec << "\n";
    cout << "  BEARER: " << (int)p.bearer << "\n";
    cout << "  DIRECTION: " << (int)p.direction
         << " (" << (p.direction ? "DL" : "UL") << ")\n";
    cout << "  Ciphering: " << p.cipher_alg << "\n";
    cout << "  Integrity: " << p.integ_alg << "\n\n";

    cout << "Processing Order (TX Side):\n";

    if (is_srb) {
        cout << "  SRB (Signaling Bearer):\n";
        cout << "  1. Compute MAC-I\n";
        cout << "  2. Append MAC-I\n";
        cout << "  3. Cipher (Data + MAC-I)\n";
    }
    else {
        cout << "  DRB (Data Bearer):\n";
        cout << "  1. Cipher Data\n";

        if (p.integ_alg != "NIA0")
            cout << "  2. Compute MAC-I\n";
    }

    cout << "\nCOUNT Structure:\n";
    cout << "  HFN: " << (p.count >> 12) << "\n";
    cout << "  SN : " << (p.count & 0xFFF) << "\n";
}

/* ============================================================
   PART 2: ROHC HEADER COMPRESSION
   ============================================================ */

// ROHC Profiles
const map<uint16_t, string> ROHC_PROFILES = {
    {0x0000, "Uncompressed"},
    {0x0001, "RTP/UDP/IP"},
    {0x0002, "UDP/IP"},
    {0x0003, "ESP/IP"},
    {0x0004, "IP-only"},
    {0x0006, "TCP/IP"},
    {0x0101, "RTP/UDP/IP (v2)"},
    {0x0102, "UDP/IP (v2)"}
};

// ROHC Simulation
void simulate_rohc() {

    cout << "Original Headers:\n";

    int ip_hdr = 20;
    int udp_hdr = 8;

    int total_hdr = ip_hdr + udp_hdr;

    cout << "  IP Header  : " << ip_hdr << " Bytes\n";
    cout << "  UDP Header : " << udp_hdr << " Bytes\n";
    cout << "  Total      : " << total_hdr << " Bytes\n\n";

    cout << "ROHC States:\n";
    cout << "  IR: ~" << total_hdr + 4 << " Bytes\n";
    cout << "  FO: ~8-12 Bytes\n";
    cout << "  SO: ~1-4 Bytes\n\n";

    vector<pair<string, int>> packets = {
        {"IR", 44},
        {"FO", 10},
        {"SO", 3},
        {"SO", 3},
        {"SO", 1},
        {"SO", 1},
        {"SO", 1},
        {"FO", 8},
        {"SO", 1}
    };

    int total_orig = 0;
    int total_comp = 0;

    cout << "Packet Compression Sequence:\n";

    for (int i = 0; i < packets.size(); i++) {

        total_orig += 28 + 100;        // header + payload
        total_comp += packets[i].second + 100;

        cout << "  Packet " << i + 1 << ": "
             << packets[i].first
             << " | Header = " << packets[i].second << " Bytes\n";
    }

    cout << "\nTotal Savings:\n";

    int saved = total_orig - total_comp;

    cout << "  Saved Bytes : " << saved << "\n";
    cout << "  Reduction   : "
         << (100 * saved / total_orig)
         << "%\n\n";

    cout << "Available ROHC Profiles:\n";

    for (auto& p : ROHC_PROFILES) {

        cout << "  0x"
             << hex << setw(4) << setfill('0') << p.first
             << dec << " : "
             << p.second << "\n";
    }
}

/* ============================================================
   MAIN FUNCTION
   ============================================================ */

int main() {

    cout << "=============================================\n";
    cout << "     5G PDCP SECURITY + ROHC SIMULATOR\n";
    cout << "=============================================\n\n";

    /* ---------------- PDCP SECURITY ---------------- */

    cout << "=== PDCP Security (TS 38.323 §5.8) ===\n\n";

    PDCPSecurityParams srb_params{
        0x0001000A,
        1,
        0,
        "NEA2 (AES-CTR)",
        "NIA2 (AES-CMAC)"
    };

    cout << "--- SRB (Signaling Bearer) ---\n";
    show_security_processing(srb_params, true);

    cout << "\n--------------------------------\n\n";

    PDCPSecurityParams drb_params{
        0x00050064,
        3,
        1,
        "NEA2 (AES-CTR)",
        "NIA0 (NULL)"
    };

    cout << "--- DRB (Data Bearer) ---\n";
    show_security_processing(drb_params, false);

    cout << "\n================================\n\n";

    /* ---------------- ROHC COMPRESSION ---------------- */

    cout << "=== ROHC Header Compression (TS 38.323 §5.7.4) ===\n\n";

    simulate_rohc();

    cout << "\n=============================================\n";
    cout << "           Simulation Completed\n";
    cout << "=============================================\n";

    return 0;
}
