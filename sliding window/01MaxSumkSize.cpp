// maxsum of k sized subarray

#include<iostream>
using namespace std;
int main(){
	int a[]={1,4,2,7,6,3,5};
	int n=7; int k=4;
	int i=0, j=0; // corner of window
	int maxSum=0;
	int currS=0;
	while(j<k){
		// first we will expand window to k size
		currS+=a[j];
		j++;
	}
	maxSum=max(maxSum,currS);
	while(j<n){
		// take window to last element of an array
		// before it we have to reduce the size as we expand it from j side
		currS-=a[i];
		i++;
		currS+=a[j];
		maxSum=max(maxSum,currS);
		j++;
	}
	cout<<maxSum;
	return 0;
}