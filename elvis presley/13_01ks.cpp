#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 10

// int dp[MAX][MAX];
int items[MAX];
int weights[MAX];

int knapSack(int W, int wt[], int items[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(W+1));

    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=W; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weights[i-1] <= w){
                
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]]+items[i-1]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }

        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<W; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][W];
}

int main()
{

    int n;
    cout<<"\nEnter the no. of items: ";
    cin>>n;

    
    cout<<"\nEnter weights arr: ";

    for(int i=0; i<n; i++)
        cin>>weights[i];

    cout<<"\nEnter items arr: ";

    for(int i=0; i<n; i++)
        cin>>items[i];

    for(int i=0; i<n; i++)
    {
        cout<<weights[i] <<" "<<items[i]<<endl;
    }

    int w;
    cout<<"\nEnter knapsack capacity: ";
    cin>>w;

    cout<<"\nMaximum no. of items: "<<knapSack(w, weights, items, n);
        

    return 0;
}
