#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Function to compute the failue array in pattern
vector<int> computeFailureFunction(const string& pattern) {
    int m = pattern.length();
    vector<int> failure(m, 0); 
    int j = 0; 
    for (int i = 1; i < m; ++i) {
        // Update failure value based on previous matches
        while (j > 0 && pattern[i] != pattern[j]) {
            j = failure[j - 1]; 
        }
        // If characters match
        if (pattern[i] == pattern[j]) {
            failure[i] = j + 1;
            ++j;
        }
    }
    return failure; 
}

void KMP(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length(); 
    vector<int> failure = computeFailureFunction(pattern); 
    int i = 0, j = 0; 
    bool found = false; 
    while (i < n) {
        // If characters match, move to the next characters in both text and pattern
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
            // If pattern is fully matched, print the index and update j using failure function
            if (j == m) {
                cout << "Pattern found at index " << i - j << endl;
                j = failure[j - 1];
                found = true;
            }
        } else {
            // If characters do not match, update j using the failure function
            if (j != 0) {
                j = failure[j - 1];
            } else {
                ++i; 
            }
        }
    }
    if (!found) {
        cout << "Pattern not found in the text." << endl;
    }
}

int main() {
    string text, pattern;
    
    n
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);
    
    clock_t start = clock();
    
    KMP(text, pattern);
    
    clock_t end = clock();
    
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    
    cout << "Time taken: " << elapsed_secs << " seconds" << endl;

    return 0;
}

