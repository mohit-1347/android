#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void maxmin(int a[], int i, int j, int& max, int& min) {
    int max1, min1, mid;
    if (i == j) {
        max = min = a[i];
    } else {
        if (i == j - 1) {
            if (a[i] < a[j]) {
                max = a[j];
                min = a[i];
            } else {
                max = a[i];
                min = a[j];
            }
        } else {
            mid = (i + j) / 2;
            maxmin(a, i, mid, max, min);
            max1 = max;
            min1 = min;
            maxmin(a, mid + 1, j, max, min);
            if (max < max1)
                max = max1;
            if (min > min1)
                min = min1;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int a[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    steady_clock::time_point start = steady_clock::now();

    int max, min;
    maxmin(a, 0, n - 1, max, min);

    steady_clock::time_point end = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);

    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;
    cout << "Time taken by maxmin(): " << duration.count() << " nanoseconds" << endl;

    return 0;
}

