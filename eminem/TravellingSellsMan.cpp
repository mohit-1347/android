
#include<bits/stdc++.h>
using namespace std;

int start ;
const int MAXN = 20;
int dp[1 << MAXN][MAXN];

int rec(int mask, int node , int n , vector< vector<int> > &graph) {

    if (mask == (1 << n) - 1)
        return graph[node][start];
	
	if (dp[mask][node] != -1) {
        return dp[mask][node]; // already computed
    }
    
    int ans = 1e9 ;
    for (int i = 0 ; i < n ; i++) {
        if (mask & (1 << i)) continue ;
        int newMask = mask | (1 << i) ;

        ans = min(ans, graph[node][i] + rec(newMask, i, n, graph));
    }

    return dp[mask][node] = ans ;
}

int main() {

#ifdef ASPIREBOY
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	memset(dp, -1, sizeof(dp));
	cout<<"\nEnter number of nodes : " ;
    int n ;
    cin >> n ;
     
    cout<<"\nEnter adjacency matrix : " ;
    vector< vector<int> > graph(n, vector<int>(n, 1e9)) ;
	
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> graph[i][j];
        }
    }
	
	cout<<"\nEnter start node : " ;
    cin >> start ;

    int cost = rec(1, start, n , graph) ;

    cout << "\n\nMinimum Cost : " << cost << endl;
}

/*
    Input :

4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
0
*/
