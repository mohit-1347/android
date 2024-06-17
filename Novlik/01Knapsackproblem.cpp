// 0/1 Knapsack problem
// Kausubh Bhavsar

//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n,w;
//	cout<<"Enter total capacity of sack: "<<endl;
//	cin>>w;
//	cout<<"Enter total number of weights: "<<endl;
//	cin>>n;
//	vector<int>wt(n);
//	vector<int>pr(n);
//	cout<<"Enter weight and its profit: "<<endl;
//	for(int i=0;i<n;i++){
//		cin>>wt[i];
//		cin>>pr[i];
//	}
//	
//	vector<vector<int>>k(n+1, vector<int>(w+1));
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=w;j++){
//			if(i==0 || j==0) k[i][j]=0;
//			else if(wt[i-1]<=j) k[i][j]=max(k[i-1][j], pr[i-1]+k[i-1][j-wt[i-1]]);
//			else k[i][j]=k[i-1][j];
//		}
//	}
//	cout<<"Maximum profit will be: "<<k[n][w]<<endl;
//	return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, vector<int>> knapsack(const vector<int>& values, const vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    // Reconstruction of the items selected
    vector<int> selectedItems;
    int i = n, w = capacity;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back(i - 1);
            w -= weights[i - 1];
        }
        i -= 1;
    }

    return { dp[n][capacity], selectedItems };
}

int main() {
    vector<int> values = { 1, 2, 5, 6 };
    vector<int> weights = { 2, 3, 4, 5 };
    int capacity = 8;

    auto result = knapsack(values, weights, capacity);
    cout << "Maximum value: " << result.first << endl;
    cout << "Selected items:";
    for (int item : result.second) {
        cout << " " << item;
    }
    cout << endl;

    return 0;
}

