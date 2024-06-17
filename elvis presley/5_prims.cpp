#include <iostream>
#include <cstring>
#include <chrono> // For measuring time
using namespace std;
using namespace std::chrono;

#define Max 1000

int main() {
    int Vert;
    cout << "Enter the number of vertices: ";
    cin >> Vert;

    int G[Vert][Vert];
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < Vert; ++i) {
        for (int j = 0; j < Vert; ++j) {
            cin >> G[i][j];
        }
    }

    int no_edge;
    int visited[Vert];
    memset(visited, false, sizeof(visited));
    no_edge = 0;
    visited[0] = true;
    int row;
    int colm;
    
    cout << "Edge : Weight" << endl;

    // Measure the start time
    auto start = high_resolution_clock::now();

    while (no_edge < (Vert - 1)) {
        int min = Max;
        row = 0;
        colm = 0;
        
        for (int i = 0; i < Vert; i++) {
            if (visited[i]) {
                for (int j = 0; j < Vert; j++) {
                    if (!visited[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            row = i;
                            colm = j;
                        }
                    }
                }
            }
        }
        
        cout << row << " - " << colm << " : " << G[row][colm] << endl;
        visited[colm] = true;
        no_edge++;
    }

    // Measure the end time
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by algorithm: " << duration.count() << " microseconds" << endl;
    
    return 0;
}

