/* ============================================================
   Purpose  : CRC Attachment Simulation for Transport Block
   Question : Demonstrate CRC generation and verification
              similar to 5G NR Transport Block CRC concept
   ============================================================ */

#include <iostream>
#include <string>

using namespace std;

/* XOR operation between two binary strings */
string xorOperation(string a, string b)
{
    string result = "";
    for (int i = 1; i < b.length(); i++)
        result += (a[i] == b[i]) ? '0' : '1';
    return result;
}

/* Perform CRC Division */
string crcDivide(string data, string generator)
{
    int gen_len = generator.length();
    string temp = data.substr(0, gen_len);

    int i = gen_len;

    while (i < data.length())
    {
        if (temp[0] == '1')
            temp = xorOperation(generator, temp) + data[i];
        else
            temp = xorOperation(string(gen_len, '0'), temp) + data[i];
        i++;
    }

    if (temp[0] == '1')
        temp = xorOperation(generator, temp);
    else
        temp = xorOperation(string(gen_len, '0'), temp);

    return temp;
}

int main()
{
    string transport_block;
    string generator;

    cout << "Enter Transport Block (binary): ";
    cin >> transport_block;

    cout << "Enter Generator Polynomial (binary): ";
    cin >> generator;

    int crc_len = generator.length() - 1;

    // Append zeros
    string appended_data = transport_block + string(crc_len, '0');

    // Generate CRC
    string crc = crcDivide(appended_data, generator);

    cout << "\nGenerated CRC: " << crc << endl;

    string transmitted_block = transport_block + crc;
    cout << "Transmitted Block: " << transmitted_block << endl;

    // Receiver verification
    string remainder = crcDivide(transmitted_block, generator);

    if (remainder.find('1') == string::npos)
        cout << "CRC Check PASSED (No Error)\n";
    else
        cout << "CRC Check FAILED (Error Detected)\n";

    return 0;
}