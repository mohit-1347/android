#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(nullptr));

    int n;
    cout << "Enter the number of elements (0 to 10000): ";
    cin >> n;

    int* arr = new int[n];
    cout << "Random array of " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
        cout << arr[i] << " ";
    }
    cout << endl;

    steady_clock::time_point start = steady_clock::now();
    cout << "\nImplementing Merge sort...\n";
    mergeSort(arr, 0, n - 1);
    steady_clock::time_point end = steady_clock::now();

    cout << "\nSorted array:\n";
    printArray(arr, n);

    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Time taken by merge sort: " << duration.count() << " nanoseconds" << endl;

    delete[] arr;

    return 0;
}

