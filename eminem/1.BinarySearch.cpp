/*
	Name: Chetan Shekhar Patil
	Batch: A1
	Roll No: 17
	
	Program : Binary Search : Recursive + Iterative
			  Linear search
*/


#include<bits/stdc++.h>
using namespace std ;

int BS_recursive(vector<int> &v , int l , int r , int key) {

    if (l > r) return -1 ;

    int mid = l + (r - l) / 2 ;

    if (v[mid] == key)
        return mid ;
    else if (v[mid] > key)
        return BS_recursive(v, l, mid - 1, key) ;
    else
        return BS_recursive(v, mid + 1, r, key) ;
}


int BS_iterative(vector<int> &v , int l , int r , int key) {

    while (l <= r) {
        int mid = l + (r - l) / 2 ;
        if (v[mid] == key) return mid ;
        else if (v[mid] > key) r = mid - 1 ;
        else l = mid + 1 ;
    }

    return -1 ;
}


int linear_search(vector<int> &v , int l , int r , int key) {

    for (int i = l ; i <= r ; i++) {
        if (v[i] == key) return i ;
    }

    return -1 ;
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

        bool available = rand() % 2 ;
        int key ;
        
        key = v[rand() % n] ;
        
        sort(v.begin(), v.end()) ;

        int ind1, ind2, ind3 ;

        auto start1 = std::chrono::steady_clock::now();
        ind1 = BS_recursive(v, 0, v.size() - 1, key) ;
        auto finish1 = std::chrono::steady_clock::now();
        double time1 = std::chrono::duration_cast <
                       std::chrono::duration<double> > (finish1 - start1).count();


        auto start2 = std::chrono::steady_clock::now();
        ind2 = BS_iterative(v, 0, v.size() - 1, key) ;
        auto finish2 = std::chrono::steady_clock::now();
        double time2 = std::chrono::duration_cast <
                       std::chrono::duration<double> > (finish2 - start2).count();


        auto start3 = std::chrono::steady_clock::now();
        ind3 = linear_search(v, 0, v.size() - 1, key) ;
        auto finish3 = std::chrono::steady_clock::now();
        double time3 = std::chrono::duration_cast <
                       std::chrono::duration<double> > (finish3 - start3).count();



        cout << "--------------------------\n";
        cout << "\nInput Size = " << n << endl;
        cout << "\nKey is present at index : " << ind1 << endl;
        cout << "\nTime Taken By BS_recursive  = " << fixed << time1 << setprecision(10) << endl;
        cout << "\nTime Taken By BS_iterative  = " << fixed << time2 << setprecision(10) << endl;
        cout << "\nTime Taken By linear_search = " << fixed << time3 << setprecision(10) << endl;
        cout << "--------------------------\n\n";
    }


}
