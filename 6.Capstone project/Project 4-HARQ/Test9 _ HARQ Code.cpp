// HARQ Process Simulation - TS 38.321 §5.4
#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <array>
#include <random>

struct HARQProcess {
    int id;
    bool ndi = false; // New Data Indicator
    int rv = 0;       // Redundancy Version (0,2,3,1 cycle)
    int retx_count = 0;
    int max_retx = 4;
    bool active = false;
    std::string data;
    static const std::array<int, 4> rv_sequence;

    void new_transmission(const std::string& d) {
        data = d; ndi = !ndi; rv = 0; retx_count = 0; active = true;
        std::cout << "  HARQ[" << id << "] NEW TX: NDI=" << ndi
                  << " RV=" << rv << " data=\"" << data << "\"\n";
    }
    bool retransmit() {
        if (retx_count >= max_retx) {
            std::cout << "  HARQ[" << id << "] MAX RETX reached!\n";
            active = false; return false;
        }
        retx_count++;
        rv = rv_sequence[retx_count % 4];
        std::cout << "  HARQ[" << id << "] RETX #" << retx_count
                  << ": RV=" << rv << "\n";
        return true;
    }
    void ack() {
        std::cout << "  HARQ[" << id << "] ACK received\n";
        active = false;
    }
};
const std::array<int, 4> HARQProcess::rv_sequence = {0, 2, 3, 1};

int main() {
    std::cout << "=== HARQ Process (TS 38.321 §5.4) ===\n\n";
    std::cout << "16 parallel stop-and-wait HARQ processes\n";
    std::cout << "RV sequence: 0 -> 2 -> 3 -> 1\n\n";
    std::mt19937 rng(42);
    HARQProcess proc{0};
    proc.new_transmission("PDU-DATA-A");
    // Simulate NACK (channel error)
    std::cout << "  << NACK (CRC fail) >>\n";
    proc.retransmit();
    std::cout << "  << NACK >>\n";
    proc.retransmit();
    std::cout << "  << ACK (combining success) >>\n";
    proc.ack();
    std::cout << "\n";
    proc.new_transmission("PDU-DATA-B");
    std::cout << "  << ACK (first attempt) >>\n";
    proc.ack();
    return 0;
}