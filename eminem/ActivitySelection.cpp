
/*
    Assume that, There are N Person and each person
    needs exactly one cab. For each person you are
    given the start time and end time (both inclusive)
    during which that person will travel. Find the
    Minimum number of cans required. Which Strategy
    will be best suitable to solve this problem.
*/


#include<bits/stdc++.h>
using namespace std ;

int main() {

#ifdef ASPIREBOY
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int n ;
    cin >> n ;

    vector< pair<int, int> > v(n) ;

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second ;
    }

    sort(v.begin(), v.end()) ;

    multiset<int> cabs ;

    int ans = 0 ;
    for (int i = 0 ; i < n ; i++) {
        int entryTime = v[i].first ;
        int exitTime = v[i].second ;

        auto it = cabs.upper_bound(entryTime);

        if (it == cabs.begin()) {
            ans++ ;
            cabs.insert(exitTime) ;
        }
        else {
            --it ;
            cabs.erase(it);
            cabs.insert(exitTime) ;
        }
    }

    cout << ans << endl;
}
