#include <iostream>
#include <cstdlib>   // rand()
#include <ctime>     // time()
using namespace std;

// Simulate unreliable channel
bool channelOK() {
    return rand() % 2;   // 50% chance success / failure
}

// ---------------- RECEIVER ----------------
bool receiver(int seqNo) {
    if (!channelOK()) {
        cout << "Receiver: Packet lost\n";
        return false;
    }

    cout << "Receiver: Packet " << seqNo << " received\n";

    if (!channelOK()) {
        cout << "Receiver: ACK lost\n";
        return false;
    }

    cout << "Receiver: ACK sent for packet " << seqNo << endl;
    return true;
}

// ---------------- SENDER ----------------
void sender(int totalPackets) {
    int seqNo = 0;

    for (int pkt = 0; pkt < totalPackets; ) {
        cout << "\nSender: Sending packet " << seqNo << endl;

        if (receiver(seqNo)) {
            cout << "Sender: ACK received for packet " << seqNo << endl;
            pkt++;               // move to next packet
            seqNo = 1 - seqNo;   // toggle seq no (0 ↔ 1)
        } else {
            cout << "Sender: Timeout → Retransmitting packet " << seqNo << endl;
        }
    }
}

// ---------------- MAIN ----------------
int main() {
    srand(time(0));   // random seed

    int totalPackets = 5;
    sender(totalPackets);

    cout << "\n✔ Transmission completed using Stop-and-Wait ARQ\n";
    return 0;
}
