


#include<bits/stdc++.h>
using namespace std;


// ------- Divide N Conquor starts -------
int get_random(int l,int r){
	int val = rand() % (r-l+1) ;
	return l + val ;
}

int partition1(int l , int r , vector<int> &arr) {
    
    int rand_ind = get_random(l,r) ;
    int pivot_element = arr[rand_ind] ;
    
    int pivot_ind = l ;
	
    for (int i = l ; i <= r ; i++) {
        if (arr[i] < pivot_element) {
        	if(pivot_ind == rand_ind){
        		rand_ind = i ;
        		swap(arr[i], arr[pivot_ind]);
			}
			else
            	swap(arr[i], arr[pivot_ind]);
            pivot_ind++;
        }
    }
	
	// putting pivot element to its correct position
    swap(arr[rand_ind] , arr[pivot_ind]) ;

    return pivot_ind ;
}

void quicksort1(vector<int> &v,int l , int r) {

    if (l >= r) return;

    int pivot_index = partition1(l, r, v) ;

    quicksort1(v,l, pivot_index - 1) ;
    quicksort1(v,pivot_index + 1, r) ;
}
// ------- Divide N Conquor ends -------



// ------- Median OF Medians starts -------

// Find the median of the medians in a subarray
int findMedian(vector<int>& arr, int start, int end) {
    if (end - start <= 5) {
        sort(arr.begin() + start, arr.begin() + end);
        return arr[(start + end) / 2];
    }

    // Divide the subarray into groups of 5 elements
    vector<int> medians;
    for (int i = start; i <= end; i += 5) {
        int subEnd = min(i + 4, end);
        sort(arr.begin() + i, arr.begin() + subEnd);
        medians.push_back(arr[(i + subEnd) / 2]);
    }

    // Recursively find the median of the medians
    int medianOfMedians = findMedian(medians, 0, medians.size() - 1);
    return medianOfMedians;
}

// Partition the array around a pivot
int partition2(vector<int>& arr, int start, int end, int pivot) {
    int pivotIdx = start;
    for (int i = start; i <= end; i++) {
        if (arr[i] == pivot) {
            pivotIdx = i;
            break;
        }
    }
    swap(arr[pivotIdx], arr[end]);
    pivotIdx = end;
    int i = start - 1;
    for (int j = start; j < pivotIdx; j++) {
        if (arr[j] < arr[pivotIdx]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pivotIdx]);
    return i + 1;
}

// Quick sort algorithm using medians of medians for pivot selection
void quicksort2(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pivot = findMedian(arr, start, end);
        int partitionIdx = partition2(arr, start, end, pivot);
        quicksort2(arr, start, partitionIdx - 1);
        quicksort2(arr, partitionIdx + 1, end);
    }
}
// ------- Median OF Medians Ends -------


int main() {
	
	cout<<fixed<<setprecision(10);
	for (int i = 1 ; i <= 6 ; i++) {

        int n = pow(10, i) ;
        vector<int> v(n) ;

        for (int i = 0 ; i < n ; i++) {
            int val = rand() % n ;
            v[i] = val ;
        }

        auto start1 = std::chrono::steady_clock::now();
        quicksort1(v,0, v.size() - 1) ;
        auto finish1 = std::chrono::steady_clock::now();
        double time1 = std::chrono::duration_cast <
                       std::chrono::duration<double> > (finish1 - start1).count();


        auto start2 = std::chrono::steady_clock::now();
        quicksort2(v, 0, v.size() - 1) ;
        auto finish2 = std::chrono::steady_clock::now();
        double time2 = std::chrono::duration_cast <
                       std::chrono::duration<double> > (finish2 - start2).count();


        cout << "--------------------------\n";
        cout << "\nInput Size = " << n << endl;
        cout << "\nTime Taken By DivideNConquor  = " << fixed << time1 << setprecision(10) << endl;
        cout << "\nTime Taken By MedianOfMedian  = " << fixed << time2 << setprecision(10) << endl;
        cout << "--------------------------\n\n";
    }
}
