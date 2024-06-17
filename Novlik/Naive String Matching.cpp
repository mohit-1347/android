// Naive Pattern Matching
// Kaustubh Bhavsar

#include<bits/stdc++.h>
using namespace std;

int main(){
	string pat, text;
	cout<<"Enter text:"<<endl;
	cin>>text;
	cout<<"Enter pattern:"<<endl;
	cin>>pat;
	int n=text.size();
	int m=pat.size();
	for(int i=0;i<=n-m;i++){
		int j=0;
		for(j=0;j<m;j++){
			if(text[i+j]!=pat[j]){
				break;
			}
		}
		if(j==m){
			cout<<"Pattern found at index: "<<i<<endl;
		}
	}
	return 0;
}
