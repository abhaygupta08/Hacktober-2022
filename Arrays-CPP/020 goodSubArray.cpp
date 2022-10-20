// Good sub array -> whose sum of elements divisible by n
// 1,6,5,2,4,3--> 6 | 2,4 | 1,6,5 | 1,6,5,2,4 == 4(TOTAL)

#include<iostream>
using namespace std;

int goodSub(int *a,int n){
	int freq[100]={};
	freq[0]=1;
	int cs=0;  // -> keep track of cs
	for(int i=0;i<n;i++){
		cs+=a[i];
		freq[cs%n]++;
	}
	int count=0;
	for(int i=0;i<n;i++){
		int x=freq[i];
		if(x>=2)
			count+=x*(x-1)/2;
	}
	return count;
}


int main(){
	int a[]={1,6,5,2,4,3};
	int n=sizeof(a)/sizeof(int);

		// brute force -> o(n^2)

	// int csum[n+1];
	// csum[0]=0;
	// for(int i=1;i<n;i++){  
	// 	csum[i]=csum[i-1]+a[i-1];  // 0,1,7,12....
	// }

	// int count=0;
	// for(int i=0;i<n;i++){
	// 	for(int j=i+1;j<n;j++){
	// 		if((csum[j+1]-csum[i])%n==0)
	// 			count++;
	// 	}
	// }	
	// cout<<count;

	cout<<goodSub(a,n);

	return 0;
}