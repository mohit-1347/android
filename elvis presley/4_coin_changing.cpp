#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve the problem without dynamic programming
int solution_no_dp(int a, vector<int>& c) {
    if (a <= 0) return 0;
    int res = INT_MAX;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] <= a) {
            int sub_res = solution_no_dp((a - c[i]), c);
            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    return res;
}

// Function to solve the problem using dynamic programming
int solution(int a, vector<int>& c, vector<int>& dp) {
    if (a < 0) return INT_MAX;
    if (a == 0) return 0;
    if (dp[a] != -1) return dp[a];
    int res = INT_MAX;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] <= a) {
            int sub_res = solution(a - c[i], c, dp);
            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    dp[a] = res;
    return dp[a];
}

// Function to solve the problem using tabulation method of dynamic programming
int tabulation(int a, vector<int>& c) {
    vector<int> dp(a + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 0; j < c.size(); j++) {
            if (c[j] <= i) {
                int sub_res = dp[i - c[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                    dp[i] = sub_res + 1;
            }
        }
    }
    if (dp[a] == INT_MAX)
        return -1;
    return dp[a];
}

// Function to solve the problem for a single test case
void solve() {
    int n, a;
    cout << "Enter the number of coin denominations: ";
    cin >> n;
    cout << "Enter the target amount: ";
    cin >> a;
    vector<int> c(n, 0);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<int> dp(a + 1, -1);
    cout << "Minimum total number of coins required: " << solution(a, c, dp) << endl;
    cout << "Minimum total number of coins required using Tabular Method of DP: " << tabulation(a, c) << endl;
}

int main() {
    solve();
    return 0;
}

