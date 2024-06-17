#include <bits/stdc++.h>
#define INF 1000000007
#define ll long long int
using namespace std;

void Prims()
{
    int min_weight;
    int edges;
    cout << "Enter number of vertices : ";
    cin >> edges;
    int G[edges][edges];
    cout << "Enter the adjacancy matrix : " << endl;
    for (int i = 0; i < edges; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            cin >> G[i][j];
        }
    }
    int no_edge = 0;
    int selected[edges];
    memset(selected, false, sizeof(selected));
    selected[0] = true;
    int x;
    int y;
    cout << "Edge"
         << " : "
         << "Weight" << endl;
    while (no_edge < edges - 1)
    {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < edges; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < edges; j++)
                {
                    if (!selected[j] && G[i][j])
                    { // not in selected and there is an edge
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        min_weight += G[x][y];
        cout << x << " - " << y << " : " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    cout << "The minimum weight(distance) through the prim's algorithm of the graph is : " << min_weight;
}

int main()
{
    Prims();
    return 0;
}