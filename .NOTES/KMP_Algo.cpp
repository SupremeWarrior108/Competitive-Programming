#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * KMP Algorithm for Efficient String Matching
 * 
 * Uses of KMP Algorithm:
 * 1. String Matching:
 *    - Efficiently finds occurrences of a substring (pattern) within a larger string (text).
 *    - Useful for search functionalities in text editors and search engines.
 * 
 * 2. Bioinformatics:
 *    - Used for DNA sequence matching and other pattern recognition tasks within biological data.
 * 
 * 3. Data Processing:
 *    - Helps in data mining and analysis where pattern matching is required in large datasets.
 * 
 * 4. Compiler Design:
 *    - Utilized in lexical analysis for recognizing tokens in source code.
 * 
 * Key Features:
 * 1. Efficiency:
 *    - Time Complexity: O(n + m), where n is the length of the text and m is the length of the pattern.
 * 
 * 2. Preprocessing:
 *    - Preprocesses the pattern to build a prefix function array (LPS array), allowing skipping unnecessary comparisons during the search phase.
 * 
 * 3. Space Complexity:
 *    - Requires O(m) space for the prefix function array.
 * 
 * Time and Space Complexity:
 * 1. Time Complexity:
 *    - Prefix Function Calculation: O(m)
 *    - Pattern Matching: O(n)
 *    - Overall: O(n + m)
 * 
 * 2. Space Complexity:
 *    - Prefix Function Array: O(m)
 */

// Function to build the prefix function (LPS array)
vector<int> buildPrefixFunction(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int length = 0; // length of the previous longest prefix suffix
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

// KMP Algorithm for pattern matching
void KMP(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    
    // Build the LPS array
    vector<int> lps = buildPrefixFunction(pattern);
    
    int i = 0; // index for text
    int j = 0; // index for pattern
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    cout << "Searching for pattern '" << pattern << "' in text '" << text << "'..." << endl;
    KMP(text, pattern);
    
    return 0;
}
