#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cstring>
#include <string>

using namespace std;

/* ============================================================
   PDCP SECURITY CONTEXT (3GPP TS 33.501)
   ============================================================ */
struct SecurityContext {
    uint8_t integrity_key[16];   // KRRCint or KUPint
    uint32_t count;              // COUNT = HFN || PDCP SN
    uint8_t bearer;              // Radio Bearer ID
    uint8_t direction;           // 0 = UL, 1 = DL
    bool is_srb;                 // true = SRB, false = DRB
};

/* ============================================================
   PDCP PDU STRUCTURE
   ============================================================ */
struct PDCP_PDU {
    uint8_t header[2];           // PDCP header (plaintext)
    uint8_t data[256];           // Payload
    size_t data_len;
    uint32_t mac_i;              // Integrity field
};

/* ============================================================
   UTILITY: HEX PRINT
   ============================================================ */
void print_hex(const string& label, const uint8_t* data, size_t len) {
    cout << label << ": 0x";
    for (size_t i = 0; i < len; i++) {
        cout << hex << setw(2) << setfill('0') << (int)data[i];
    }
    cout << dec << endl;
}

/* ============================================================
   SIMPLIFIED MAC-I CALCULATION (DEMO ONLY)
   ============================================================ */
uint32_t calculate_mac_i(const uint8_t* data, size_t len,
                         uint32_t count, uint8_t bearer,
                         uint8_t direction, const uint8_t* key)
{
    uint32_t mac = 0;

    for (size_t i = 0; i < len; i++) {
        mac ^= (data[i] << ((i % 4) * 8));
        mac ^= key[i % 16];
    }

    mac ^= count;
    mac ^= (bearer << 1);
    mac ^= direction;

    return mac;
}

/* ============================================================
   TRANSMITTER: INTEGRITY PROTECTION
   ============================================================ */
void apply_integrity_protection(PDCP_PDU& pdu, SecurityContext& ctx)
{
    cout << "\n[TRANSMITTER] Applying Integrity Protection\n";

    pdu.mac_i = calculate_mac_i(
        pdu.data,
        pdu.data_len,
        ctx.count,
        ctx.bearer,
        ctx.direction,
        ctx.integrity_key
    );

    cout << "  → MAC-I generated: 0x" << hex << pdu.mac_i << dec << endl;
}

/* ============================================================
   RECEIVER: INTEGRITY VERIFICATION
   ============================================================ */
bool verify_integrity(const PDCP_PDU& pdu, SecurityContext& ctx)
{
    cout << "\n[RECEIVER] Verifying Integrity\n";

    uint32_t x_mac = calculate_mac_i(
        pdu.data,
        pdu.data_len,
        ctx.count,
        ctx.bearer,
        ctx.direction,
        ctx.integrity_key
    );

    cout << "  → Received MAC-I : 0x" << hex << pdu.mac_i << endl;
    cout << "  → Calculated X-MAC: 0x" << x_mac << dec << endl;

    if (x_mac != pdu.mac_i) {
        cout << "   INTEGRITY FAILURE DETECTED\n";
        return false;
    }

    cout << "   Integrity verification SUCCESSFUL\n";
    return true;
}

/* ============================================================
   INTEGRITY FAILURE HANDLING
   ============================================================ */
void handle_integrity_failure(const SecurityContext& ctx)
{
    cout << "\n[SECURITY ACTION]\n";

    if (ctx.is_srb) {
        cout << "   SRB Integrity Failure\n";
        cout << "  Discard PDCP PDU\n";
        cout << " Raise security alarm\n";
        cout << "   Trigger RRC re-establishment\n";
        cout << "  Possible connection release\n";
    } else {
        cout << "   DRB Integrity Failure\n";
        cout << "   Discard user data PDU\n";
        cout << "   Connection continues\n";
    }
}

/* ============================================================
   MAIN DEMONSTRATION
   ============================================================ */
int main()
{
  cout << "PROGRAM STARTED\n";

    cout << "============================================\n";
    cout << " 5G NR PDCP INTEGRITY PROTECTION DEMO\n";
    cout << "============================================\n";

    /* ---------- Security Context ---------- */
    SecurityContext ctx{};
    ctx.count = 0x00000010;
    ctx.bearer = 1;
    ctx.direction = 0;      // Uplink
    ctx.is_srb = true;      // Change to false for DRB

    const char* key = "0123456789ABCDEF";
    memcpy(ctx.integrity_key, key, 16);

    /* ---------- PDCP PDU ---------- */
    PDCP_PDU pdu{};
    strcpy((char*)pdu.data, "RRC Security Mode Command");
    pdu.data_len = strlen((char*)pdu.data);

    cout << "\n[INPUT DATA]\n";
    cout << "  → Payload: " << pdu.data << endl;
    cout << "  → Bearer Type: " << (ctx.is_srb ? "SRB" : "DRB") << endl;

    /* ---------- TRANSMITTER ---------- */
    apply_integrity_protection(pdu, ctx);

    /* ---------- ATTACK SIMULATION ---------- */
    cout << "\n[ATTACK SIMULATION] Modifying data...\n";
    pdu.data[0] ^= 0xFF;   // Flip bits to simulate attack

    /* ---------- RECEIVER ---------- */
    bool integrity_ok = verify_integrity(pdu, ctx);

    if (!integrity_ok) {
        handle_integrity_failure(ctx);
        cout << "\n[RESULT] PDU processing stopped due to integrity failure\n";
        return 0;
    }

    cout << "\n[RESULT] PDU accepted and delivered to upper layers\n";
    return 0;
}
