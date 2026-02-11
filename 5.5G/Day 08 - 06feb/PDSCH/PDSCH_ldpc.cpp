/* ============================================================
   Purpose  : LDPC Base Graph Selection Simulation
   Question : Demonstrate Base Graph selection logic used in
              5G NR Physical Layer before LDPC encoding
   ============================================================ */

#include <iostream>
using namespace std;

int main()
{
    int tb_size;
    float coding_rate;

    cout << "Enter Transport Block Size (bits): ";
    cin >> tb_size;

    cout << "Enter Target Coding Rate (0 to 1): ";
    cin >> coding_rate;

    cout << "\n--- LDPC Base Graph Selection ---\n";

    int base_graph;

    /* 3GPP-based simplified decision logic */
    if ((tb_size <= 292) ||
        (coding_rate <= 0.25) ||
        (tb_size <= 3824 && coding_rate <= 0.67))
    {
        base_graph = 2;
    }
    else
    {
        base_graph = 1;
    }

    cout << "Selected Base Graph : BG" << base_graph << endl;

    if (base_graph == 1)
    {
        cout << "\nReason:\n";
        cout << "- Large transport block or higher coding rate\n";
        cout << "- Optimized for throughput\n";
        cout << "- Lower redundancy compared to BG2\n";
    }
    else
    {
        cout << "\nReason:\n";
        cout << "- Small transport block or low coding rate\n";
        cout << "- Higher error protection required\n";
        cout << "- Stronger decoding reliability\n";
    }

    return 0;
}