#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;

int* generateRandomArray(int size) {
    int *array = new int[size];
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 10000 + 1;
    }
    return array;
}

void displayArray(int arr[], int size) {
    for(int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int pivotIndex = i + 1;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

bool linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            cout << "Linear Search: Element found at index " << i << "\n";
            return true;
        }
    }
    cout << "Linear Search: Element not found\n";
    return false;
}

bool binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            cout << "Binary Search Iterative: Element found at index " << mid << "\n";
            return true;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << "Binary Search Iterative: Element not found\n";
    return false;
}

bool binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) {
        cout << "Binary Search Recursive: Element not found\n";
        return false;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        cout << "Binary Search Recursive: Element found at index " << mid << "\n";
        return true;
    }
    else if (arr[mid] > target) {
        return binarySearchRecursive(arr, low, mid - 1, target);
    }
    else {
        return binarySearchRecursive(arr, mid + 1, high, target);
    }
}

int main() {
    int arraySize;
    cout << "Enter the size of input array: ";
    cin >> arraySize;

	auto startTime = chrono::steady_clock::now();

    int* inputArray = generateRandomArray(arraySize);
    auto endTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

    cout << "\nThe Input array is:" << "\n";
    displayArray(inputArray, arraySize);
    cout << "\n" << "Time Taken for Array Creation: " << duration << " nanoSec" << "\n\n\n";

    int target;
    cout << "Enter Value to Search: ";
    cin >> target;

    // Quick Sort
    auto quickSortTimeStart = chrono::steady_clock::now();
    quickSort(inputArray, 0, arraySize - 1);
    auto quickSortTimeStop = chrono::steady_clock::now();
    auto quickSortDuration = chrono::duration_cast<chrono::nanoseconds>(quickSortTimeStop - quickSortTimeStart).count();

    cout << "Time Taken for Quick Sort: " << quickSortDuration << " nanoSec" << "\n";

    startTime = chrono::steady_clock::now();
    linearSearch(inputArray, arraySize, target);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

    cout << "Time Taken for Linear Search (SORTED): " << duration << " nanoSec" << "\n\n";

    // Binary Search Iterative
    startTime = chrono::steady_clock::now();
    binarySearch(inputArray, arraySize, target);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

    cout << "Time Taken for Binary Search Iterative : " << duration << " nanoSec" << "\n";
    cout << "Time Taken for Binary Search Iterative (INCLUDING SORT TIME): " << duration + quickSortDuration << " nanoSec" << "\n\n\n";

    // Binary Search Recursive
    startTime = chrono::steady_clock::now();
    binarySearchRecursive(inputArray, 0, arraySize, target);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

    cout << "Time Taken for Binary Search Recursive : " << duration << " nanoSec" << "\n";
    cout << "Time Taken for Binary Search Recursive (INCLUDING SORT TIME): " << duration + quickSortDuration << " nanoSec" << "\n\n";


    return 0;
}

