#include<iostream>
#include<vector>
using namespace std;

template<typename T>

void bubble(vector<T> &arr){
	int n = arr.size();
	for(int i =0 ;i<n-1;i++){
		for(int j =0 ;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j+1],arr[j]);
			}
		}
	}
}
template<typename T>
void insert(vector<T> &arr){
	int n = arr.size();
	for(int i =1;i<n;i++){
		T key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j] > key){
			arr[j+1] =arr[j];
			j--;
		}
		arr[j+1] =key;
	}
}

template<typename T>
void select(vector<T> &arr){
	int n = arr.size();
	for(int i = 0;i<n-1;i++){
		int minpos = i;
		for(int j = i+1;j<n;j++){
			if(arr[j]<arr[minpos]){
				minpos = j;
			}
		}
		swap(arr[i] ,arr[minpos]);
	}
}

int main(){
	vector<int> arr1 = {2,4,3,7,5,9};
	//cout<<"original array"<<arr1<<endl;
	for(auto i : arr1){
		cout<<i<<" ";
	}
	cout<<endl;
	 
	bubble(arr1);
	cout<<"bubble sort"<<endl;
	for(auto i : arr1){
		cout<<i<<" ";
	}
	cout<<endl;
	
	 arr1 = {2,5,3,7,5,9};
	insert(arr1);
	cout<<"insert sort"<<endl;
	for(auto i :arr1){
		cout<<i<<" ";
	}
	cout<<endl;
	
	 arr1 = {2,5,3,7,5,9};
	select(arr1);
	cout<<"select sort "<<endl;
	for(auto i :arr1){
		cout<<i<<" ";
	}
	cout<< endl;
}
