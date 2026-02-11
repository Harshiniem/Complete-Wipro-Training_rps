/*
 * PDCP Ciphering Simulation in C++
 * This program demonstrates a simplified version of 5G PDCP ciphering using XOR-based encryption.
 */

#include <iostream>   // Used for input and output operations (cout, endl)
#include <vector>     // Provides std::vector to store byte data dynamically
#include <string>     // Used for handling text data
#include <cstdint>    // Provides fixed-width integer types (uint32_t, uint8_t)

using namespace std;  // Avoids writing std:: repeatedly, improves readability

struct SecurityContext {
    uint32_t key;      // 32-bit ciphering key (simulated)
    uint8_t bearerId;  // Identifies the radio bearer
    bool isUplink;     // true  -> Uplink (UE → Network)
                       // false -> Downlink (Network → UE)
};


class PDCP {
public:

    static vector<uint8_t> cipher(
        const vector<uint8_t>& data,   // Input payload (plain or encrypted)
        uint32_t count,                 // PDCP COUNT value
        const SecurityContext& secCtx   // Security parameters
    ) {
        // Stores the output after encryption or decryption
        vector<uint8_t> result;

        // Iterate byte-by-byte over input data
        for (size_t i = 0; i < data.size(); i++) {

            // XOR-based ciphering logic (reversible)
            uint8_t cipherByte =
                data[i] ^

                // Extract one byte from 32-bit key (cyclic usage)
                ((secCtx.key >> ((i % 4) * 8)) & 0xFF) ^

                // Include COUNT value for freshness and replay protection
                ((count >> ((i % 4) * 8)) & 0xFF) ^

                // Include bearer ID to differentiate traffic
                secCtx.bearerId ^

                // Direction-specific variation
                (secCtx.isUplink ? 0xAA : 0x55);

            // Store the computed cipher byte
            result.push_back(cipherByte);
        }

        // Return encrypted or decrypted output
        return result;
    }
};

// Converts string data into byte array (PDCP works on bytes)
vector<uint8_t> stringToBytes(const string& s) {
    return vector<uint8_t>(s.begin(), s.end());
}

// Converts byte array back into string after decryption
string bytesToString(const vector<uint8_t>& v) {
    return string(v.begin(), v.end());
}

int main() {

    // Sample payload to be encrypted
    string message = "This is our first Project.";

    // Simulated PDCP COUNT value (increments per packet in real systems)
    uint32_t COUNT = 0x12345678;

    // Initialize security context
    SecurityContext secCtx;
    secCtx.key = 0xA1B2C3D4;   // Ciphering key
    secCtx.bearerId = 1;       // Radio bearer ID
    secCtx.isUplink = true;    // Uplink direction

    // Convert plaintext message to byte format
    vector<uint8_t> plainData = stringToBytes(message);

    // Encryption Process
     
    vector<uint8_t> encryptedData =
        PDCP::cipher(plainData, COUNT, secCtx);

    
     // Decryption Process
     
    vector<uint8_t> decryptedData =
        PDCP::cipher(encryptedData, COUNT, secCtx);

    cout << "Original Data   : " << message << endl;

    cout << "Encrypted Bytes : ";
    for (auto b : encryptedData)
        cout << hex << (int)b << " ";
    cout << endl;

    cout << "Decrypted Data  : "
         << bytesToString(decryptedData) << endl;
         
         cout << "Decrypted Bytes : ";
for (auto b : decryptedData)
    cout << hex << (int)b << " ";
cout << endl;


    return 0;
}
