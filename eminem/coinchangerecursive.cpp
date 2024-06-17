/*
    Name: Chetan Shekhar Patil
    Batch: A1
    Roll No: 17

    Program : Coin change recursive
*/ 


#include<bits/stdc++.h>
using namespace std;

int f(int total , int sum , vector<int> &v, int i , vector<vector<int>> &dp) {
    if (sum == total) return 0 ;
    if (i == v.size())
        return 1e9 ;

    if (dp[sum][i] != -1) return dp[sum][i] ;
    int t = 1e9 , nt = 1e9 ;

    if (sum + v[i] <= total) {
        t = 1 + f(total, sum + v[i], v, i, dp) ;
    }

    nt = f(total, sum, v, i + 1, dp) ;

    return dp[sum][i] = min(t, nt) ;
}

int main() {

#ifdef ASPIREBOY
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
	
	char inf = 236 ;
	
    cout << "\nEnter different number of coins : " ;
    int n ; cin >> n ;
    vector<int> v(n) ;

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i] ;
    }

    cout << "\nEnter sum you want : ";
    int total ;
    cin >> total ;

    vector<vector<int>> dp(total + 1, vector<int>(n + 1, -1)) ;

    int ans = f(total, 0, v, 0, dp) ;
    
    if (ans == 1e9) cout << "\nNot Possible\n" ;
    else{
    	cout<<"\nAnswer is : ";
    	cout << ans << endl;
    	
    	cout<<"\nDP Table : \n";
    	for(int i = 0 ; i < n ; i++){
    		for(int sum = 0 ; sum <= total ; sum++){
    			if(dp[sum][i] == 1e9) cout<<inf<<"\t";
    			else cout<<dp[sum][i]<<"\t";
			}
    		cout<<endl;
		}
		cout<<endl;
	}
	
	/*
	
		Time Complexity of solution will be :
		
		O (Required_sum * Number_Of_different_coins)
	
	*/
    
    
}
