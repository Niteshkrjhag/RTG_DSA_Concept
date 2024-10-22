/*

    string getBinaryRep(int N)
    {
        string b = "";
        for(int i=0;i<32;i++){
            int a = (N&(1<<i));
            b +=to_string(a);
        }
        return b;
    }

Flaw => The expression int a = (N & (1 << i)); extracts the i-th bit from N, but it does not convert it to a binary digit (0 or 1). Instead, it retrieves the value of that bit as either 0 or a power of 2. For example, if the 3rd bit is set, a would be 8 (which is 2^3), not 1.


*/
   




#include <string>
using namespace std;

string getBinaryRep(int N) {
    string b = "";
    for (int i = 31; i >= 0; i--) {  // Loop from 31 to 0 for MSB to LSB
        int a = (N & (1 << i)) ? 1 : 0;  // Check if the i-th bit is set (1) or not (0)
        b += to_string(a);  // Append the bit (0 or 1) to the string
    }
    return b;
}
