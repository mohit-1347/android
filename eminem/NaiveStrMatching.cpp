#include<bits/stdc++.h>
using namespace std ;

/*
	Name : Chetan Shekhar Patil
	Batch : A1
	Roll No : 17
*/

// Naive String Matching
// Time Complexity : O ((n-m+1)*m)

int main() {

#ifdef ASPIREBOY
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	cout << "\nEnter Text : " ;
	string text ;
	cin >> text ;

	cout << "\nEnter Pattern : " ;
	string pattern ;
	cin >> pattern ;

	int n = text.length() , m = pattern.length() ;

	vector<int> answer ;

	for (int i = 0 ; i + m <= n ; i++ ) {
		bool matches = true ;
		for (int j = 0 ; j < m ; j++) {
			if (pattern[j] != text[i + j]) {
				matches = false ;
				break;
			}
		}
		if (matches) {
			answer.push_back(i) ;
		}
	}

	if (answer.size() == 0) {
		cout << "\nPattern Does Not Exist";
	}
	else {
		for (int i = 0 ; i < answer.size() ; i++) {
			cout << "\nPattern Found at index " << answer[i] << endl;
		}
	}
}
