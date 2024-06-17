#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> // Include chrono for time measurement

using namespace std;

// Function to swap two elements
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to partition the array using the leftmost pivot
int partitionLeft(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, high);
    return i;
}

// Function to perform random partition
int partitionRight(int arr[], int low, int high) {
    srand(time(NULL));
    int r = low + rand() % (high - low);
    swap(arr, r, high);
    return partitionLeft(arr, low, high);
}

// Recursive function for quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionRight(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    // Get user input for the array size
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate an array of size n
    int* arr = new int[n];

    // Get user input for the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print the original array
    cout << "Original array: ";
    printArray(arr, n);

    // Start the timer using high_resolution_clock
    auto start = chrono::high_resolution_clock::now();

    // Call the quicksort function
    quicksort(arr, 0, n - 1);

    // Stop the timer
    auto end = chrono::high_resolution_clock::now();

    // Calculate the execution time in nanoseconds
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(arr, n);

    // Output the execution time
    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;

    // Free the allocated memory
    delete[] arr;

    return 0;
}
