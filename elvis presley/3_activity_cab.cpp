#include <bits/stdc++.h>
using namespace std;

// Custom comparator function for sorting
static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first < p2.first;
}

// Function to solve the problem for each test case
void solve() {
    int n;
    cin >> n; // Read the number of elements in the array

    // Create a vector of pairs to store the array elements
    vector<pair<int, int>> vec(n);

    // Read the first array and store the values in the first element of each pair
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first;
    }

    // Read the second array and store the values in the second element of each pair
    for (int i = 0; i < n; i++) {
        cin >> vec[i].second;
    }

    // If there is only one element, the answer is 1
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    // Sort the array of pairs based on the first element
    sort(vec.begin(), vec.end());

    // Print the sorted first array (for debugging purposes)
    for (int i = 0; i < n; i++) {
        cout << vec[i].first << " ";
    }
    cout << '\n';

    // Print the second array corresponding to the sorted first array (for debugging purposes)
    for (int i = 0; i < n; i++) {
        cout << vec[i].second << " ";
    }
    cout << '\n';

    // Initialize variables for the maximum contiguous subarray sum
    int maxi = 0; // Maximum sum found so far
    int initial = 0; // Starting index of the current subarray
    int cabs = 1; // Length of the current contiguous subarray

    // Iterate through the array and find the maximum sum
    for (int i = 1; i < n; i++) {
        // Check if the current pair overlaps with the initial pair
        if (vec[initial].second > vec[i].first) {
            // If there is overlap, increase the length of the current contiguous subarray
            if (vec[i - 1].second > vec[i].first) {
                cabs++;
            }
        } else {
            // If there is no overlap, adjust the starting index of the subarray
            while (initial != i) {
                initial++;
                if (vec[i].first > vec[initial].second) {
                    cabs--;
                }
            }
        }
        // Update the maximum sum found so far
        maxi = max(maxi, cabs);
    }

    // Output the maximum contiguous subarray sum
    cout << maxi << '\n';
}

// Main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Solve the problem for the current test case
    }

    return 0;
}
