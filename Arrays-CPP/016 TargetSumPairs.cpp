#include<iostream>
using namespace std;


// QUADRATIC COMPLEXITY
// int targetPair(int* a, int n , int t){
// 	int count=0;
// 	for(int i=0;i<n-1;i++){
// 		for(int j=i+1;j<n;j++){
// 			if(a[i]+a[j]==t)
// 				count++;
// 		}
// 	}
// 	return count;
// }


// LINEAR COMPLEXITY -2 pointer appproch
int targetPair(int* arr, int n, int t){
	int count=0;
	int i=0;
	int j=n-1;
	while(i<j){
		if(arr[i]+arr[j]==t){
			count++;
			i++; j--;
			}
		else if(arr[i]+arr[j]>t)
			j--;
		else
			i++;
		}
		return count;
}



int main(){
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(int);
	int t=6;
	cout<<targetPair(a,n,t);
}