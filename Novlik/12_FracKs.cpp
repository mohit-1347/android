#include <bits/stdc++.h>
#include <chrono>
using namespace std;

struct Item {
    int profit, weight;
    Item(int profit, int weight) {
        this->profit = profit;
        this->weight = weight;
    }
    Item() {
        this->profit = 0;
        this->weight = 0;
    }
};

static bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int N) {
    sort(arr, arr + N, cmp);
    double finalvalue = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        } else {
            finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}

int main() {
    int W;
    cout << "Enter the weight capacity of the knapsack: ";
    cin >> W;
    int N;
    cout << "Enter the number of items: ";
    cin >> N;
    Item* arr = new Item[N];
    for (int i = 0; i < N; i++) {
        int profit, weight;
        cout << "Enter profit and weight of item " << (i + 1) << ": ";
        cin >> profit >> weight;
        arr[i] = Item(profit, weight);
    }
    auto start = chrono::steady_clock::now();
    double maxProfit = fractionalKnapsack(W, arr, N);
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Maximum profit in the knapsack: " << maxProfit << endl;
    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;
    delete[] arr;
    return 0;
}
/*Enter the weight capacity of the knapsack: 50
Enter the number of items: 3
Enter profit and weight of item 1: 60 10
Enter profit and weight of item 2: 100 20
Enter profit and weight of item 3: 120 30
*/

