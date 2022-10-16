//given an array of n integer representing height of n building. 
//Find total water can be trapped bw buildings..


#include<iostream>
using namespace std;

int totalWater(int *a, int n){
	
	int total=0;
	int wi;
	for(int i=0;i<n;i++){ //loop to iterate every building
		int hi=a[i]; //height of each building

		// l max : height of tallest building to the left of the ith building 
		int lmax=hi;
		for(int j=i-1;j>=0;j--){
			lmax=max(lmax,a[j]);
		}

		// r max : height of tallest building to the right of the ith building
		int rmax=hi;
		for(int j=i+1;j<n;j++){
			rmax=max(rmax,a[j]);
		} 

		wi=min(lmax,rmax)-hi;
		total+=wi;
	}

	return total;
}
	

int main(){
	
	int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
	int n=sizeof(a)/sizeof(int);
	
	cout<<totalWater(a,n);
	return 0;
}