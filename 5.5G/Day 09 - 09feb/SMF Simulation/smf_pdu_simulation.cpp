/* ============================================================
Purpose  : 5G Core SMF PDU Session Establishment Simulation
Question : Simulate SMF based PDU Session Establishment
           including UPF selection, IP allocation,
           QoS flow creation and session verification.
Author   : (Your Name)
Date     : (Submission Date)
============================================================ */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/* ---------------- PDU SESSION STRUCT ---------------- */
struct PDUSession
{
    int session_id;
    string dnn;
    string ip_address;
    int fteid;
    bool voice_qos;
    bool video_qos;
    bool active;
};

/* ---------------- GLOBAL SESSION ---------------- */
PDUSession session;

/* ---------------- SIMPLE TIMESTAMP ---------------- */
string getTimeStamp()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    return to_string(ltm->tm_hour) + ":" +
           to_string(ltm->tm_min) + ":" +
           to_string(ltm->tm_sec);
}

/* ---------------- RANDOM IP ---------------- */
string generateIP()
{
    int last = rand() % 200 + 1;
    return "10.1.0." + to_string(last);
}

/* ---------------- RANDOM F-TEID ---------------- */
int generateFTEID()
{
    return rand() % 9000 + 1000;
}

/* ---------------- CREATE SESSION ---------------- */
void createPDUSession(string dnn_type)
{
    cout << "\n===== PDU SESSION ESTABLISHMENT =====\n";

    cout << "[" << getTimeStamp() << "] AMF : PDU Session Request Received\n";
    cout << "[" << getTimeStamp() << "] SMF : Selecting UPF\n";
    cout << "[" << getTimeStamp() << "] PCF : Providing PCC Rules\n";
    cout << "[" << getTimeStamp() << "] SMF : Creating N4 Session\n";

    session.session_id = 1;
    session.dnn = dnn_type;
    session.ip_address = generateIP();
    session.fteid = generateFTEID();
    session.voice_qos = false;
    session.video_qos = false;
    session.active = true;

    cout << "[" << getTimeStamp() << "] UPF : IP Allocated -> "
         << session.ip_address << endl;

    cout << "[" << getTimeStamp() << "] UPF : F-TEID -> "
         << session.fteid << endl;

    cout << "[" << getTimeStamp() << "] SMF : PDU Session Established\n";
}

/* ---------------- ADD VOICE QOS ---------------- */
void addVoiceQoS()
{
    if (!session.active)
    {
        cout << "No active session!\n";
        return;
    }

    session.voice_qos = true;
    cout << "[" << getTimeStamp()
         << "] Voice QoS Added (5QI = 1)\n";
}

/* ---------------- ADD VIDEO QOS ---------------- */
void addVideoQoS()
{
    if (!session.active)
    {
        cout << "No active session!\n";
        return;
    }

    session.video_qos = true;
    cout << "[" << getTimeStamp()
         << "] Video QoS Added (5QI = 2)\n";
}

/* ---------------- SHOW SESSION ---------------- */
void showSessionInfo()
{
    if (!session.active)
    {
        cout << "No active session available!\n";
        return;
    }

    cout << "\n===== SESSION INFORMATION =====\n";
    cout << "Session ID : " << session.session_id << endl;
    cout << "DNN        : " << session.dnn << endl;
    cout << "IP Address : " << session.ip_address << endl;
    cout << "F-TEID     : " << session.fteid << endl;

    cout << "QoS Flows  : ";
    if (!session.voice_qos && !session.video_qos)
        cout << "Default";
    else
    {
        if (session.voice_qos) cout << "Voice ";
        if (session.video_qos) cout << "Video ";
    }
    cout << endl;
}

/* ---------------- MAIN ---------------- */
int main()
{
    srand(time(0));
    session.active = false;

    int choice;

    while (true)
    {
        cout << "\n===== 5G SMF PDU SESSION SIMULATOR =====\n";
        cout << "1. Internet PDU Session\n";
        cout << "2. IMS PDU Session\n";
        cout << "3. Add Voice QoS\n";
        cout << "4. Add Video QoS\n";
        cout << "5. Show Session Info\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                createPDUSession("internet");
                break;

            case 2:
                createPDUSession("ims");
                break;

            case 3:
                addVoiceQoS();
                break;

            case 4:
                addVideoQoS();
                break;

            case 5:
                showSessionInfo();
                break;

            case 0:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}