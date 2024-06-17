#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstring>
using namespace std;
using namespace std::chrono;

const int MAXN = 15; // Maximum number of cities

int dist[MAXN][MAXN]; // Distance matrix
int dp[MAXN][1 << MAXN]; // DP table

int tsp(int u, int mask, int n) {
    if (mask == (1 << n) - 1)
        return dist[u][0];

    if (dp[u][mask] != -1)
        return dp[u][mask];

    int min_cost = INT_MAX;
    for (int v = 0; v < n; ++v) {
        if (!(mask & (1 << v)))
            min_cost = min(min_cost, dist[u][v] + tsp(v, mask | (1 << v), n));
    }

    return dp[u][mask] = min_cost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the distance matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];
    }

    auto start = high_resolution_clock::now();
    memset(dp, -1, sizeof(dp));
    int min_cost = tsp(0, 1, n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Minimum cost of the TSP tour is: " << min_cost << endl;
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}

