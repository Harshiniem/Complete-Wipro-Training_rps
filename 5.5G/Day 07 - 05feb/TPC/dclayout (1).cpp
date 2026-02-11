/*
============================================================
Purpose : 5G NR DC Payload Processing Demonstration
Question: Show DC payload flow through PHY stages
============================================================
*/

#include <iostream>
#include <vector>
#include <random>

using namespace std;

/* ---------- Print Bits ---------- */
void printBits(const vector<int>& bits, string title)
{
    cout << title << " : ";
    for(int b : bits) cout << b;
    cout << endl;
}

/* ---------- Generate DC Payload ---------- */
vector<int> generatePayload(int size)
{
    vector<int> payload(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,1);

    for(int i=0;i<size;i++)
        payload[i] = dis(gen);

    return payload;
}

/* ---------- Simple CRC (Parity Demo) ---------- */
vector<int> attachCRC(vector<int> payload)
{
    int parity = 0;
    for(int b : payload)
        parity ^= b;

    payload.push_back(parity);
    return payload;
}

/* ---------- Rate Matching (Repetition) ---------- */
vector<int> rateMatch(const vector<int>& in, int E)
{
    vector<int> out;
    for(int i=0;i<E;i++)
        out.push_back(in[i % in.size()]);
    return out;
}

/* ---------- Scrambling Sequence ---------- */
vector<int> generateScrambleSeq(int len, int cellID)
{
    vector<int> seq(len);
    for(int i=0;i<len;i++)
        seq[i] = (i + cellID) % 2;
    return seq;
}

/* ---------- XOR Scrambling ---------- */
vector<int> scramble(const vector<int>& data,
                     const vector<int>& seq)
{
    vector<int> out(data.size());

    for(size_t i=0;i<data.size();i++)
        out[i] = data[i] ^ seq[i];

    return out;
}

/* ---------- MAIN ---------- */
int main()
{
    cout << "\n===== DC PAYLOAD SIMULATION =====\n\n";

    // 1. DC Payload
    auto payload = generatePayload(16);
    printBits(payload,"Original DC Payload");

    // 2. CRC
    auto crcPayload = attachCRC(payload);
    printBits(crcPayload,"After CRC Attachment");

    // 3. Rate Matching
    auto rm = rateMatch(crcPayload,24);
    printBits(rm,"After Rate Matching");

    // 4. Scrambling
    int cellID = 276;
    auto seq = generateScrambleSeq(rm.size(),cellID);
    auto scrambled = scramble(rm,seq);

    printBits(seq,"Scrambling Sequence");
    printBits(scrambled,"Scrambled Output");

    cout << "\nXOR Operation:\n";
    for(size_t i=0;i<rm.size();i++)
        cout << rm[i] << " XOR "
             << seq[i] << " = "
             << scrambled[i] << endl;

    cout << "\nSimulation Completed\n";
    return 0;
}