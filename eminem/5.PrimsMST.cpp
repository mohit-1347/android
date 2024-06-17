/*
    Name: Chetan Shekhar Patil
    Batch: A1
    Roll No: 17

    Program : Minimum Spanning Tree using Prims Algorithm
*/ 

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>>

typedef long long ll;


int main() {

#ifdef ASPIREBOY
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n, m;
    cin >> n >> m;

    vector<vpll> edges(n + 1) ;

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    set<pll> pq;

    vll dist(n + 1, 1e9);

    dist[1] = 0;

    vector<bool> visited(n + 1);

    vll parent(n + 1, -1);

    pq.insert({0, 1});

    for (int i = 0; i < n; i++) {
        pll top = *pq.begin();
        pq.erase(top);

        ll best = top.ss;

        visited[best] = true;

        for (auto i : edges[best]) {
            if ((!visited[i.ff]) && dist[i.ff] > i.ss) {
                pq.erase({dist[i.ff], i.ff});
                dist[i.ff] = i.ss;
                pq.insert({dist[i.ff], i.ff});
                parent[i.ff] = best;
            }
        }
    }

    cout << "Minimum spanning tree is : \n";
    for (int i = 2; i <= n; i++) {
        if (parent[i] < i) {
            cout << parent[i] << " " << i << " " << dist[i] << endl;
        } else {
            cout << i << " " << parent[i] << " " << dist[i] << endl;
        }
    }

    ll mstcost = accumulate(dist.begin() + 1, dist.end(), 0ll);
    cout << "\nMST_Cost = " << mstcost << endl;
	
}



/*

The input graph has V vertices 
and E edges. The algorithm runs V times, selecting 
one vertex at each step. For each selected vertex, 
it iterates over all its adjacent edges to find 
the one with the smallest weight. Since each edge 
is considered at most twice (once for each of its 
endpoints), the total number of edge comparisons 
is 2E.

Therefore, the overall time complexity of Prim's 
algorithm with a heap priority queue is O(E log V).

*/
