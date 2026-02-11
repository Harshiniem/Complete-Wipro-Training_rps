/*
============================================================
Purpose : Polar Encoding Demonstration (5G NR Concept)
Question: Show Polar coding XOR transformation
============================================================
*/

#include <iostream>
#include <vector>

using namespace std;

/* ---------- Print Bits ---------- */
void printBits(const vector<int>& bits, string title)
{
    cout << title << " : ";
    for(int b : bits) cout << b;
    cout << endl;
}

/* ---------- Polar Transform (N = 8 Demo) ---------- */
vector<int> polarEncode(vector<int> u)
{
    cout << "\n--- Polar Encoding Steps ---\n";

    // Stage 1
    cout << "\nStage 1 XOR:\n";
    for(int i=0;i<8;i+=2)
    {
        cout << u[i] << " XOR " << u[i+1];
        u[i] = u[i] ^ u[i+1];
        cout << " = " << u[i] << endl;
    }

    // Stage 2
    cout << "\nStage 2 XOR:\n";
    for(int i=0;i<8;i+=4)
    {
        cout << u[i] << " XOR " << u[i+2];
        u[i] = u[i] ^ u[i+2];
        cout << " = " << u[i] << endl;

        cout << u[i+1] << " XOR " << u[i+3];
        u[i+1] = u[i+1] ^ u[i+3];
        cout << " = " << u[i+1] << endl;
    }

    // Stage 3
    cout << "\nStage 3 XOR:\n";
    for(int i=0;i<4;i++)
    {
        cout << u[i] << " XOR " << u[i+4];
        u[i] = u[i] ^ u[i+4];
        cout << " = " << u[i] << endl;
    }

    return u;
}

/* ---------- MAIN ---------- */
int main()
{
    cout << "\n===== POLAR ENCODING DEMO =====\n\n";

    // N = 8 example
    vector<int> input = {1,0,1,0,1,0,0,0};

    printBits(input,"Input Bits (Info + Frozen)");

    auto encoded = polarEncode(input);

    printBits(encoded,"\nEncoded Output");

    cout << "\nPolar Encoding Completed\n";
    return 0;
}