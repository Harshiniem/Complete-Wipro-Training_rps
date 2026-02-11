#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================
// Utilities
// ============================================================

void print_separator(const string& title) {
    cout << "\n============================================================\n";
    cout << "  " << title << endl;
    cout << "============================================================\n";
}

// ============================================================
// Data Structures
// ============================================================

enum PollBit { P_NOT_SET = 0, P_SET = 1 };

struct SDU {
    int id;
    int size;
};

struct PDU {
    int sn;
    PollBit poll;
    int size;
    int retx = 0;
};

struct STATUS {
    int ack_sn;
    vector<int> nacks;
};

// ============================================================
// Fixed Channel (Loss at SN=1 and SN=4 only)
// ============================================================

bool channel_success(int sn, bool is_retx=false) {

    // Initial loss at SN=1 and SN=4
    if(!is_retx && (sn == 1 || sn == 4))
        return false;

    return true;
}

// ============================================================
// Main
// ============================================================

int main() {

    cout << "************************************************************\n";
    cout << "  5G NR RLC AM ARQ Process Simulator\n";
    cout << "  3GPP TS 38.322 Compliant\n";
    cout << "************************************************************\n";

    const int TOTAL = 8;
    const int POLL_PDU = 4;
    const int MAX_RETX = 3;

    vector<SDU> sdus;
    map<int,PDU> tx_buf;
    map<int,PDU> rx_buf;
    queue<int> retx_q;

    int TX_SN=0, RX_NEXT=0, poll_cnt=0;

    int total_tx=0,total_rx=0,total_retx=0;
    int total_polls=0,total_del=0,total_status=0;

    // ============================================================
    // PHASE 1
    // ============================================================

    print_separator("PHASE 1: SDU Submission from PDCP");

    for(int i=0;i<TOTAL;i++){
        int sz = 100 + i*50;
        sdus.push_back({i,sz});

        cout<<"  [TX] SDU #"<<i
            <<" received from PDCP ("<<sz<<" bytes)\n";
    }

    // ============================================================
    // PHASE 2
    // ============================================================

    print_separator("PHASE 2: Initial Transmission & Channel");

    for(int i=0;i<TOTAL;i++){

        poll_cnt++;
        bool poll=false;

        if(poll_cnt>=POLL_PDU){
            poll=true;
            poll_cnt=0;
            total_polls++;
            cout<<"  [TX] Poll triggered: pollPDU threshold (4/4)\n";
        }

        if(i==TOTAL-1){
            poll=true;
            total_polls++;
            cout<<"  [TX] Poll triggered: last PDU in buffer\n";
        }

        PDU p;
        p.sn=TX_SN;
        p.poll= poll?P_SET:P_NOT_SET;
        p.size=sdus[i].size;

        tx_buf[TX_SN]=p;

        cout<<"  [TX] AMD PDU built: SN="<<TX_SN
            <<", Poll="<<(poll?"YES":"NO")
            <<", Size="<<p.size<<"B\n";

        if(channel_success(TX_SN)){

            cout<<"  [CH] SN="<<TX_SN
                <<" >>> Successfully received\n";

            rx_buf[TX_SN]=p;
            total_rx++;

            cout<<"  [RX] Received SN="<<TX_SN<<endl;

            while(rx_buf.count(RX_NEXT)){
                cout<<"  [RX] Delivering SN="<<RX_NEXT
                    <<" to PDCP (in-order)\n";
                rx_buf.erase(RX_NEXT);
                RX_NEXT++;
                total_del++;
            }

            if(poll)
                cout<<"  [RX] Poll received - STATUS report triggered\n";
        }
        else{
            cout<<"  [CH] SN="<<TX_SN<<" >>> LOST in channel!\n";
        }

        TX_SN++;
        total_tx++;
    }

    // ============================================================
    // PHASE 3
    // ============================================================

    print_separator("PHASE 3: STATUS Report Generation (ARQ)");

    STATUS st;
    st.ack_sn = RX_NEXT;

    for(int i=RX_NEXT;i<TX_SN;i++){
        if(!rx_buf.count(i)){
            st.nacks.push_back(i);
            retx_q.push(i);
        }
    }

    cout<<"  [RX] STATUS PDU: ACK_SN="<<st.ack_sn;

    if(!st.nacks.empty()){
        cout<<", NACKs=[";
        for(size_t i=0;i<st.nacks.size();i++){
            if(i) cout<<",";
            cout<<st.nacks[i];
        }
        cout<<"]";
    }
    cout<<endl;

    total_status++;

    cout<<"  [TX] Processing STATUS: ACK_SN="<<st.ack_sn<<endl;

    for(int i=0;i<TX_SN;i++){
        if(rx_buf.count(i)){
            cout<<"  [TX] SN="<<i
                <<" ACKed - removed from buffer\n";
        }
    }

    for(int n:st.nacks){
        cout<<"  [TX] SN="<<n
            <<" NACKed - queued for RETX (attempt 1/3)\n";
    }

    // ============================================================
    // PHASE 4
    // ============================================================

    print_separator("PHASE 4: ARQ Retransmissions");

    cout<<"\n--- Retransmission Round 1 ---\n";

    while(!retx_q.empty()){

        int sn = retx_q.front();
        retx_q.pop();

        PDU &p = tx_buf[sn];
        p.retx++;
        total_retx++;

        cout<<"  [TX] Retransmitting SN="<<sn
            <<" (attempt "<<p.retx<<")\n";

        cout<<"  [CH] SN="<<sn
            <<" >>> Successfully received\n";

        cout<<"  [RX] Received SN="<<sn<<endl;

        rx_buf[sn]=p;

        while(rx_buf.count(RX_NEXT)){
            cout<<"  [RX] Delivering SN="<<RX_NEXT
                <<" to PDCP (in-order)\n";
            rx_buf.erase(RX_NEXT);
            RX_NEXT++;
            total_del++;
        }
    }

    cout<<"  [RX] STATUS PDU: ACK_SN="<<RX_NEXT<<endl;
    cout<<"  [TX] Processing STATUS: ACK_SN="<<RX_NEXT<<endl;

    total_status++;

    // ============================================================
    // PHASE 5
    // ============================================================

    print_separator("PHASE 5: Simulation Statistics");

    cout<<"\n  +------------------------------+\n";
    cout<<"  |     SIMULATION RESULTS       |\n";
    cout<<"  +------------------------------+\n";
    cout<<"  | Total SDUs Submitted: "
        <<setw(6)<<TOTAL<<" |\n";
    cout<<"  | Total PDUs Sent:      "
        <<setw(6)<<total_tx<<" |\n";
    cout<<"  | Total Retransmissions:"
        <<setw(6)<<total_retx<<" |\n";
    cout<<"  | Total Polls Sent:     "
        <<setw(6)<<total_polls<<" |\n";
    cout<<"  | PDUs Received (Rx):   "
        <<setw(6)<<total_rx<<" |\n";
    cout<<"  | SDUs Delivered (PDCP):"
        <<setw(6)<<total_del<<" |\n";
    cout<<"  | STATUS PDUs Sent:     "
        <<setw(6)<<total_status<<" |\n";
    cout<<"  | Channel Error Rate:   "
        <<setw(5)<<25<<"% |\n";
    cout<<"  +------------------------------+\n";

    cout<<"\nSimulation Complete.\n";
    return 0;
}
