#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;

int GreedyCoinChange(int amount, vector<int> &coins)
{
    sort(coins.begin(), coins.end(), greater<int>());
    int n = coins.size();
    int number_coin = 0;
    for (auto i = 0; i < n; i++)
    {
        number_coin += amount / coins[i];
        amount %= coins[i];
        if (amount < coins[i])
        {
        }
    }
    return number_coin;
}

int CoinChange(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i)
    {
        for (int coin : coins)
        {
            if (coin <= i && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main()
{
    srand(0);
    set<int> uniqueCoins;
    int numCoins = rand() % 5;
    while (uniqueCoins.size() < numCoins)
    {
        uniqueCoins.insert(1 + rand() % 10);
    }
    vector<int> coins(uniqueCoins.begin(), uniqueCoins.end());
    int amount = rand() % 500;
    cout << "Coins: ";
    for (int coin : coins)
    {
        cout << coin << " ";
    }
    cout << endl;
    cout << "Amount: " << amount << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Using greedy strategy -> " << endl;
    cout << "Number of coins needed: " << GreedyCoinChange(amount, coins) << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Using dynamic programming approach -> " << endl;
    cout << "Minimum number of coins needed: " << CoinChange(amount, coins) << endl;

    return 0;
}