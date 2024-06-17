/*
	Name: Chetan Shekhar Patil
	Batch: A1
	Roll No: 17
	
	Program : Quick Sort
*/


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


        cout << "--------------------------\n";
        cout << "\nInput Size = " << n << endl;
        cout << "\nTime Taken By DivideNConquor  = " << fixed << time1 << setprecision(10) << endl;
        cout << "--------------------------\n\n";
    }
}
