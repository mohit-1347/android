// Quicksort Randomised
// Kaustubh Bhavsar
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int partition(vector<int>&arr, int l, int h){
	int pivot=arr[l];
	int k=h;
	for(int i=h;i>l;i--){
		if(arr[i]>pivot){
			swap(arr[i],arr[k]);
			k--;
		}
	}
	swap(arr[l],arr[k]);
	return k;
}

int partition_r(vector<int>&arr, int l, int h){
	int ran=l+rand()%(h-l);
	swap(arr[ran],arr[l]);
	return partition(arr,l,h);
}

void quicksort(vector<int>&v, int l, int h){
	if(l<h){
		int par=partition_r(v,l,h);
		quicksort(v,l,par-1);
		quicksort(v,par+1,h);
	}
}

int main(){
	int n;
	vector<int>v;
	cout<<"Enter size of vector: "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		v.push_back(rand()%1000);	
	}
	cout<<"Your vector is:"<<endl;
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	
	auto start= high_resolution_clock::now();
	quicksort(v,0,n-1);	
	auto end=high_resolution_clock::now();
	auto duration=duration_cast<nanoseconds>(end-start);
	
	cout<<"Your sorted vector is: "<<endl;
	for(auto x:v){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"Total time taken is: "<<duration.count()<<" ms"<<endl;
	return 0;
}	
