/*
NAME: Mohit Lalwani
ROLL NO.: 121
PRN: 202101040154
BATCH: B2
*/

#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#define mod 100000007
#define ll long long int
using namespace std;
using namespace std::chrono;

bool linearSearch(int arr[], int key, int i, int size)
{
    if (i == size)
    {
        return false;
    }
    if (arr[i] == key)
    {
        cout << key << " found at " << i << endl;
        return true;
    }
    return linearSearch(arr, key, i + 1, size);
}

bool BinarySearch(int arr[], int l, int r, int key)
{
    if (l == r)
    {
        if (arr[l] == key)
        {
            cout << key << " found at " << l << endl;
            return true;
        }
        else
            return false;
    }
    else if (l > r)
        return false;
    else
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
        {
            cout << key << " found at " << mid << endl;
            return true;
        }
        else if (arr[mid] > key)
            return BinarySearch(arr, l, mid - 1, key);
        else
            return BinarySearch(arr, mid + 1, r, key);
    }
}

bool binarySearch(int arr[], int l, int r, int key)
{
    if (l == r)
    {
        if (arr[l] == key)
        {
            cout << key << " found at " << l << endl;
            return true;
        }
        else
            return false;
    }
    else if (l > r)
        return false;
    else
    {
        int mid = (rand() % (r - l + 1)) + l;
        if (arr[mid] == key)
        {
            cout << key << " found at " << mid << endl;
            return true;
        }
        else if (arr[mid] > key)
            return binarySearch(arr, l, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, r, key);
    }
}

int main()
{
    long long int size = 20000 * (rand() % 9);
    // cout << size << endl;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 20000;
    // cout << arr[size - 1] << endl;
    int num;
    bool flag = false;
    cout << "Enter the number to search : ";
    cin >> num;
    // auto start = chrono::high_resolution_clock::now();
    auto start = clock();
    bool ls = linearSearch(arr, num, 0, size);
    if (!ls)
        cout << num << " not found" << endl;
    // auto end = high_resolution_clock::now();
    auto end = clock();
    auto duration = static_cast<microseconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    sort(arr, arr + size);
    start = clock();
    bool bs = BinarySearch(arr, 0, size - 1, num);
    // cout << bs;
    if (!bs)
        cout << num << " not found" << endl;
    end = clock();
    duration = static_cast<microseconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    start = clock();
    bool Bs = binarySearch(arr, 0, size - 1, num);
    // cout << bs;
    if (!Bs)
        cout << num << " not found" << endl;
    end = clock();
    duration = static_cast<microseconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}