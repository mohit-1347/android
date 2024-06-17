// Activity Selection Problem
// Kaustubh Bhavsar

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"Enter total number of activities: "<<endl;
	cin>>n;
	vector<pair<int,int>>v(n);
	cout<<"Enter start time and finishing time of each activity: "<<endl;
	for(int i=0;i<n;i++){
		cin>>v[i].first;
		cin>>v[i].second;
	}
	sort(v.begin(),v.end(),[] (const pair<int,int> &a, const pair<int,int> &b){
		return a.second<b.second;
	});
	cout<<"Activities sorted as per finishing times are: "<<endl;
	for(auto x:v){
		cout<<x.first<<" "<<x.second<<endl;
	}
	int cnt=1;
	int indd=0;
	vector<pair<int,int>>ans;
	ans.push_back({v[0].first, v[0].second});
	for(int i=1;i<n;i++){
		if(v[i].first>v[indd].second){
			ans.push_back({v[i].first, v[i].second});
			indd=i;
			cnt++;
		}
	}
	cout<<"Total activities selected: "<<cnt<<endl;
	for(auto x:ans){
		cout<<x.first<<" "<<x.second<<endl;
	}
	return 0;
}
