#include <bits/stdc++.h>
#include <chrono> // Include chrono for time measurement
using namespace std;

#define NO_OF_CHARS 256

// The preprocessing function for Boyer Moore's
// bad character heuristic
void badCharHeuristic(const string &str, int size, int badchar[NO_OF_CHARS]) {
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence of each character in the string
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void search(const string &txt, const string &pat) {
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    // Fill the bad character array by calling badCharHeuristic()
    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is the shift of the pattern with respect to the text
    while (s <= (n - m)) {
        int j = m - 1;

        // Keep reducing index j of pattern while characters of pattern and text match at the current shift
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        // If the pattern is present at the current shift
        if (j < 0) {
            cout << "Pattern occurs at shift = " << s << endl;

            /* Shift the pattern so that the next character in the text aligns with the last occurrence
            of it in the pattern. The condition s + m < n is necessary for the case when pattern occurs at the end of the text. */
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        } else {
            /* Shift the pattern so that the bad character in text aligns with the last occurrence of it in the pattern.
            The max function is used to make sure we get a positive shift. */
            s += max(1, j - badchar[txt[s + j]]);
        }
    }
}

int main() {
	
    string txt, pat;
    cout << "Enter the text: ";
    getline(cin, txt);
    cout << "Enter the pattern: ";
    getline(cin, pat);

    auto start = chrono::high_resolution_clock::now();
    search(txt, pat);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;

    return 0;
}
