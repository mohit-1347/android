#include <iostream>
#include <string>
#include <chrono>
using namespace std;

void StringMatch(string text, string pattern) {
    int t = text.length();
    int p = pattern.length();

    int i = 0;
    int j = 0;
    int flag = 0;

    while (i < t && j < p) {
        if (text[i] == pattern[j]) {
            flag = 1;
            i++;
            j++;
        } else if (flag == 1) {
            i = i - 1 + 1;
            j = 0;
            flag = 0;
        } else {
            i++;
        }

        if (j == p) {
            cout << "\nString match found at index: " << i - p + 1 << endl;
            break;
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);

    auto start = chrono::steady_clock::now();
    StringMatch(text, pattern);
    auto end = chrono::steady_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Execution time: " << duration << " nanoseconds" << endl;

    return 0;
}

