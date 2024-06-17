/*
    Name: Chetan Shekhar Patil
    Batch: A1
    Roll No: 17

    Program : Coin change iterative
*/ 


#include<bits/stdc++.h>
using namespace std;

int main() {

#ifdef ASPIREBOY
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
	
	cout<<"\nEnter number of elements and target sum : " ;
    int n, target;
    cin >> n >> target;
    vector<int> c(n);
    for (int&v : c) cin >> v;

    vector<int> dp(target + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0) {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    
    
  cout << (dp[target] == 1e9 ? -1 : dp[target]) << endl;
	
}
