

// Brute Force

int minRepeats(string A, string B) {
    // Store the original string A for reuse in appending
    string rep = A;
    
    // Initialize the repetition count (we start with one repetition of A)
    int cnt = 1;

    // Keep repeating A until its size is greater than or equal to the size of B
    while (A.size() < B.size()) {
        A += rep;  // Append A to itself
        cnt++;     // Increment the repetition count
    }

    // Check if B is a substring of the repeated A
    if (A.find(B) != -1) return cnt;  // If found, return the current count of repetitions

    // If not found, repeat A one more time
    A += rep;
    cnt++;  // Increment the count again

    // Check again if B is a substring of the new repeated A
    if (A.find(B) != -1) return cnt;  // If found, return the current count of repetitions

    // If B is still not found, return -1, meaning it's not possible
    return -1;
}


String Concatenation:
 The loop runs approximately O(m / n) times (where m is the size of B and n is the size of A).

find() Operation:
 The find() function searches for B in A, which takes O(n * m) in the worst case. This operation is done twice, leading to a total complexity of O(m²).











// Optimize Form 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to build the prefix (partial match) array for KMP algorithm
vector<int> buildPrefixArray(const string& pattern) {
    int m = pattern.size();  // Length of the pattern (s2)
    vector<int> prefix(m, 0);  // Initialize the prefix array with 0
    int len = 0;  // Length of the previous longest prefix suffix
    int i = 1;  // Start from the second character of the pattern

    // Building the prefix array
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;  // Increase the length of the matched prefix
            prefix[i] = len;  // Store the length in the prefix array
            i++;  // Move to the next character
        } else {
            if (len != 0) {
                len = prefix[len - 1];  // Backtrack in the prefix array
            } else {
                prefix[i] = 0;  // No prefix, set to 0
                i++;  // Move to the next character
            }
        }
    }
    return prefix;  // Return the prefix array
}

// KMP string matching function to search for the pattern (s2) in the text (comp)
bool KMPSearch(const string& text, const string& pattern) {
    vector<int> prefix = buildPrefixArray(pattern);  // Build the prefix array for the pattern
    int n = text.size();  // Length of the text (repeated string A)
    int m = pattern.size();  // Length of the pattern (s2)
    int i = 0;  // Index for the text
    int j = 0;  // Index for the pattern

    // Searching for the pattern in the text using the KMP algorithm
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;  // Move to the next character in the text
            j++;  // Move to the next character in the pattern
        }

        // If the whole pattern is found
        if (j == m) {
            return true;  // Pattern found, return true
        }

        // If there's a mismatch
        else if (i < n && pattern[j] != text[i]) {
            // Use the prefix array to skip unnecessary comparisons
            if (j != 0) {
                j = prefix[j - 1];  // Move back in the pattern using the prefix array
            } else {
                i++;  // Move to the next character in the text
            }
        }
    }
    return false;  // Pattern not found
}

// Main function to find the minimum number of repetitions of A for B to become a substring
int minRepeats(string A, string B) {
    int repetitions = 1;  // We start with one repetition of A
    string comp = A;  // Initialize the repeated string with A

    // Repeat A until its length is large enough to potentially contain B
    while (comp.size() < B.size()) {
        comp += A;  // Append A to the repeated string
        repetitions++;  // Increment the repetition count
    }

    // Check if B is a substring of the repeated string comp
    if (KMPSearch(comp, B)) {
        return repetitions;  // If found, return the number of repetitions
    }

    // Repeat one more time and check again
    comp += A;
    repetitions++;
    if (KMPSearch(comp, B)) {
        return repetitions;  // If found after one more repetition, return the count
    }

    // If B is not found after sufficient repetitions, return -1
    return -1;
}

int main() {
    string A = "abcd";
    string B = "cdabcdab";
    int result = minRepeats(A, B);
    cout << "Minimum repetitions: " << result << endl;  // Expected output: 3
    return 0;
}


Time Complexity Breakdown:

buildPrefixArray:

The time complexity of building the prefix array is O(m), where m is the length of B.
KMPSearch:
Searching for the pattern B in the string comp takes O(n + m), where n is the length of comp and m is the length of B.

minRepeats:

The number of repetitions is roughly proportional to the length of B, so the total time complexity is O(m) (since comp.size() will be close to m after the loop ends).
Overall, the time complexity of minRepeats is O(m), since each KMP search is O(n + m), and n is proportional to m due to the number of repetitions.

Final Time Complexity:

Time Complexity: O(m), where m is the length of string B.
Space Complexity: O(m) for storing the prefix array and comp.