
/*	
	Name : Chetan Shekhar Patil
	Batch : A1
	Roll No : 17
	
    Assume that, There are N Person and each person
    needs exactly one cab. For each person you are
    given the start time and end time (both inclusive)
    during which that person will travel. Find the
    Minimum number of cans required. Which Strategy
    will be best suitable to solve this problem.

    By descending end time

*/


#include<bits/stdc++.h>
using namespace std ;

int main() {
	
	cout << "\n Enter Number Of People : " ;
    int n ;
    cin >> n ;

    vector<pair<int, int>> v(n) ;
	
	cout<< "\n Enter start time and end time of n persons : ";
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second ;
    }

    sort(v.begin(), v.end() , [&](pair<int, int> p1 , pair<int, int> p2) {
        if (p1.second == p2.second) return p1.first > p2.first ;
        return p1.second > p2.second ;
    }) ;

    set<int> taken ;

    int cab = 1 , i = 0 ;

    while (taken.size() < n) {

        cout << "\nBy Cab " << cab << endl;
        cab++ ;

        int prev = 1e9 ;

        for (int i = 0 ; i < n ; i++) {
            if (taken.find(i) != taken.end()) continue ;
            if (v[i].second > prev)
                continue ;

            cout << v[i].first << " " << v[i].second << endl;
            taken.insert(i) ;
            prev = v[i].first ;

        }
    }

    cout << "\nTotal Cabs Required = " << cab - 1 << endl;
}
