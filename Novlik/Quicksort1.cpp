#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <bits/stdc++.h>

#define ll long long

using namespace std;
using namespace chrono;

// Function to find the median of the given list
ll findMedianValue(ll a, ll b, ll c)
{
    return max(min(a, b), min(max(a, b), c));
}

// Function to partition the array using the pivot
int partitionByMedian(vector<ll> &arr, ll low, ll high, ll pivot)
{
    while (low <= high)
    {
        while (arr[low] < pivot)
            low++;
        while (arr[high] > pivot)
            high--;

        if (low <= high)
        {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
    return low;
}

// Function to find the pivot using the median of medians algorithm
int findMedianOfMediansValue(vector<ll> &arr, ll low, ll high)
{
    ll n = high - low + 1;

    // Divide the array llo groups of size 5
    for (ll i = 0; i < n / 5; i++)
    {
        ll start = low + i * 5;
        ll end = start + 4;
        sort(arr.begin() + start, arr.begin() + end + 1);
        swap(arr[low + i], arr[start + 2]);
    }

    // Find the median of medians recursively
    if (n / 5 > 1)
    {
        return findMedianOfMediansValue(arr, low, low + n / 5 - 1);
    }
    else
    {
        return arr[low];
    }
}

// Function to perform quicksort using median of medians
void sortUsingMedianOfMedians(vector<ll> &arr, ll low, ll high)
{
    if (low < high)
    {
        // Find pivot using median of medians
        ll pivot = findMedianOfMediansValue(arr, low, high);

        // Partition the array
        ll partitionIndex = partitionByMedian(arr, low, high, pivot);

        // Recursively sort the sub-arrays
        sortUsingMedianOfMedians(arr, low, partitionIndex - 1);
        sortUsingMedianOfMedians(arr, partitionIndex, high);
    }
}

// Quicksort using divide and conquer
int divideAndConquerPartition(vector<ll> &arr, ll start, ll end)
{
    ll pivot = arr[end];
    ll i = start - 1;

    for (ll j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}

// Function to perform QuickSort on the array using divide and conquer
void sortUsingDivideAndConquer(vector<ll> &arr, ll start, ll end)
{
    if (start < end)
    {
        ll pivotIndex = divideAndConquerPartition(arr, start, end);
        sortUsingDivideAndConquer(arr, start, pivotIndex - 1);
        sortUsingDivideAndConquer(arr, pivotIndex + 1, end);
    }
}

// Function to measure time taken by a search algorithm
template <typename Func>
double calculateExecutionTime(Func sortingFunction, vector<ll> &arr, ll start, ll end)
{
    auto startTime = high_resolution_clock::now();
    sortingFunction(arr, start, end);
    auto stopTime = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stopTime - startTime);
    return duration.count();
}

int main()
{
    srand(time(0));

    ll n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // cout << "\nRandom elements are  :  \n";
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i)
    {
        arr[i] = rand() % 1000;
        // cout << arr[i] << " ";
    }

    // Measure time for Quick Sort using Divide and Conquer
    double q1 = calculateExecutionTime(sortUsingDivideAndConquer, arr, 0, n - 1);
    cout << "\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "Quick Sort Using Divide and Conquer Method Time: " << static_cast<long long>(q1) << " nanoseconds" << endl;

    // Measure time for Quick Sort using Median of Median
    double q2 = calculateExecutionTime(sortUsingMedianOfMedians, arr, 0, n - 1);
    cout << "Quick Sort Using Median of Medians Method Time:  " << static_cast<long long>(q2) << " nanoseconds" << endl
         << endl;

    return 0;
}