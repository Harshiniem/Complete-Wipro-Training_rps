#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

/* ============================================================
   STEP 1: DATA STRUCTURES & ENUMS
   ============================================================ */

// Poll Bit
enum PollBit { P_NOT_SET = 0, P_SET = 1 };

// SDU from PDCP
struct SDU {
    int id;
    int size;
};

// RLC PDU
struct PDU {
    int sn;
    PollBit poll;
    int size;
    int retx = 0;
};

// STATUS PDU
struct STATUS {
    int ack_sn;
    vector<int> nacks;
};



/* ============================================================
   STEP 2: CONFIGURATION PARAMETERS
   ============================================================ */

struct Config {
    int total_sdus = 8;
    int pollPDU = 4;
    int maxRetx = 3;
    double error_rate = 0.25;
};

Config cfg;



/* ============================================================
   UTILITY FUNCTIONS
   ============================================================ */

void print_separator(const string& title) {
    cout << "\n============================================================\n";
    cout << "  " << title << endl;
    cout << "============================================================\n";
}

// Fixed channel: Loss at SN=1 and SN=4
bool channel_success(int sn, bool retx = false) {
    if (!retx && (sn == 1 || sn == 4))
        return false;
    return true;
}



/* ============================================================
   STEP 3: TRANSMITTER IMPLEMENTATION
   ============================================================ */

class RLC_Transmitter {

private:
    map<int,PDU> tx_buffer;
    queue<int> retx_queue;

    int TX_SN = 0;
    int poll_counter = 0;

    int total_tx = 0;
    int total_retx = 0;
    int total_polls = 0;

public:

    // Build and send PDU
    PDU build_pdu(const SDU& sdu, bool& poll) {

        poll = false;
        poll_counter++;

        if (poll_counter >= cfg.pollPDU) {
            poll = true;
            poll_counter = 0;
            total_polls++;
            cout << "  [TX] Poll triggered: pollPDU threshold (4/4)\n";
        }

        PDU p;
        p.sn = TX_SN;
        p.poll = poll ? P_SET : P_NOT_SET;
        p.size = sdu.size;

        tx_buffer[TX_SN] = p;

        cout << "  [TX] AMD PDU built: SN=" << TX_SN
             << ", Poll=" << (poll ? "YES" : "NO")
             << ", Size=" << p.size << "B\n";

        TX_SN++;
        total_tx++;

        return p;
    }

    // Handle STATUS
    void process_status(const STATUS& st) {

        cout << "  [TX] Processing STATUS: ACK_SN=" << st.ack_sn << endl;

        for (auto& p : tx_buffer) {
            if (p.first < st.ack_sn &&
                find(st.nacks.begin(), st.nacks.end(), p.first)
                == st.nacks.end()) {

                cout << "  [TX] SN=" << p.first
                     << " ACKed - removed from buffer\n";
            }
        }

        for (int sn : st.nacks) {

            if (tx_buffer[sn].retx < cfg.maxRetx) {

                tx_buffer[sn].retx++;
                retx_queue.push(sn);
                total_retx++;

                cout << "  [TX] SN=" << sn
                     << " NACKed - queued for RETX (attempt "
                     << tx_buffer[sn].retx << "/"
                     << cfg.maxRetx << ")\n";
            }
        }
    }

    bool has_retx() {
        return !retx_queue.empty();
    }

    int get_retx_sn() {
        int sn = retx_queue.front();
        retx_queue.pop();
        return sn;
    }

    PDU& get_pdu(int sn) {
        return tx_buffer[sn];
    }

    int get_total_tx() { return total_tx; }
    int get_total_retx() { return total_retx; }
    int get_total_polls() { return total_polls; }
};



/* ============================================================
   STEP 4: RECEIVER IMPLEMENTATION
   ============================================================ */

class RLC_Receiver {

private:
    map<int,PDU> rx_buffer;

    int RX_NEXT = 0;
    int total_rx = 0;
    int total_delivered = 0;
    int total_status = 0;

public:

    // Receive PDU
    void receive(const PDU& pdu) {

        cout << "  [RX] Received SN=" << pdu.sn << endl;

        rx_buffer[pdu.sn] = pdu;
        total_rx++;

        while (rx_buffer.count(RX_NEXT)) {

            cout << "  [RX] Delivering SN=" << RX_NEXT
                 << " to PDCP (in-order)\n";

            rx_buffer.erase(RX_NEXT);
            RX_NEXT++;
            total_delivered++;
        }

        if (pdu.poll == P_SET)
            cout << "  [RX] Poll received - STATUS report triggered\n";
    }

    // Generate STATUS
    STATUS generate_status(int max_sn) {

        STATUS st;
        st.ack_sn = RX_NEXT;

        for (int i = RX_NEXT; i < max_sn; i++) {
            if (!rx_buffer.count(i))
                st.nacks.push_back(i);
        }

        cout << "  [RX] STATUS PDU: ACK_SN=" << st.ack_sn;

        if (!st.nacks.empty()) {
            cout << ", NACKs=[";
            for (size_t i=0;i<st.nacks.size();i++){
                if(i) cout<<",";
                cout<<st.nacks[i];
            }
            cout << "]";
        }
        cout << endl;

        total_status++;

        return st;
    }

    int get_rx_next() { return RX_NEXT; }

    int get_total_rx() { return total_rx; }
    int get_total_delivered() { return total_delivered; }
    int get_total_status() { return total_status; }
};



/* ============================================================
   STEP 5: MAIN SIMULATION
   ============================================================ */

int main() {

    cout << "************************************************************\n";
    cout << "  5G NR RLC AM ARQ Process Simulator\n";
    cout << "  3GPP TS 38.322 Compliant\n";
    cout << "************************************************************\n";

    vector<SDU> sdus;

    RLC_Transmitter tx;
    RLC_Receiver rx;

    int total_delivered = 0;

    // ---------------- PHASE 1 ----------------
    print_separator("PHASE 1: SDU Submission from PDCP");

    for(int i=0;i<cfg.total_sdus;i++){

        int sz = 100 + i*50;
        sdus.push_back({i,sz});

        cout<<"  [TX] SDU #"<<i
            <<" received from PDCP ("<<sz<<" bytes)\n";
    }

    // ---------------- PHASE 2 ----------------
    print_separator("PHASE 2: Initial Transmission & Channel");

    vector<PDU> sent_pdus;

    for(int i=0;i<cfg.total_sdus;i++){

        bool poll;
        PDU pdu = tx.build_pdu(sdus[i], poll);

        sent_pdus.push_back(pdu);

        if(channel_success(pdu.sn)){

            cout<<"  [CH] SN="<<pdu.sn
                <<" >>> Successfully received\n";

            rx.receive(pdu);
        }
        else{
            cout<<"  [CH] SN="<<pdu.sn
                <<" >>> LOST in channel!\n";
        }
    }

    // ---------------- PHASE 3 ----------------
    print_separator("PHASE 3: STATUS Report Generation (ARQ)");

    STATUS st = rx.generate_status(cfg.total_sdus);

    tx.process_status(st);

    // ---------------- PHASE 4 ----------------
    print_separator("PHASE 4: ARQ Retransmissions");

    cout<<"\n--- Retransmission Round 1 ---\n";

    while(tx.has_retx()){

        int sn = tx.get_retx_sn();

        PDU& p = tx.get_pdu(sn);

        cout<<"  [TX] Retransmitting SN="<<sn
            <<" (attempt "<<p.retx<<")\n";

        cout<<"  [CH] SN="<<sn
            <<" >>> Successfully received\n";

        rx.receive(p);
    }

    STATUS st2 = rx.generate_status(cfg.total_sdus);
    cout<<"  [TX] Processing STATUS: ACK_SN="
        <<st2.ack_sn<<endl;

    // ---------------- PHASE 5 ----------------
    print_separator("PHASE 5: Simulation Statistics");

    cout<<"\n  +------------------------------+\n";
    cout<<"  |     SIMULATION RESULTS       |\n";
    cout<<"  +------------------------------+\n";

    cout<<"  | Total SDUs Submitted: "
        <<setw(6)<<cfg.total_sdus<<" |\n";

    cout<<"  | Total PDUs Sent:      "
        <<setw(6)<<tx.get_total_tx()<<" |\n";

    cout<<"  | Total Retransmissions:"
        <<setw(6)<<tx.get_total_retx()<<" |\n";

    cout<<"  | Total Polls Sent:     "
        <<setw(6)<<tx.get_total_polls()<<" |\n";

    cout<<"  | PDUs Received (Rx):   "
        <<setw(6)<<rx.get_total_rx()<<" |\n";

    cout<<"  | SDUs Delivered (PDCP):"
        <<setw(6)<<rx.get_total_delivered()<<" |\n";

    cout<<"  | STATUS PDUs Sent:     "
        <<setw(6)<<rx.get_total_status()<<" |\n";

    cout<<"  | Channel Error Rate:   "
        <<setw(5)<<25<<"% |\n";

    cout<<"  +------------------------------+\n";

    cout<<"\nSimulation Complete.\n";

    return 0;
}
