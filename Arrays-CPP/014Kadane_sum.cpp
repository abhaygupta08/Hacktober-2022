//constraints n<=10

#include<iostream>
#include<math.h>
using namespace std;

int kadane(int a[],int n){
	// int x[10];
	// int final=a[0];
	//  x[0]=a[0];
	// for(int i=1;i<n;i++){
	// 	x[i]=max(a[i],a[i]+x[i-1]);
	// 	if(x[i]>final){
	// 		final=x[i];
	// 	}
	// }

	int final=a[0]; // let a[0] is max or the answer
	int x=a[0];  // to iterate we start from a[0]
	for(int i=1;i<n;i++){
		x=max(a[i],a[i]+x);
		if(x>final){
			final=x;
		}
	}
	return final;
}


 int main(){

 	int a[]={-2,1,3,4};
 	int n=sizeof(a)/sizeof(int);

 	cout<<kadane(a,n);
 	
 }