#include<iostream>
using namespace std;
int main(){
	int a[20]={3,5,7,9};
	int n=4;
	int b[]={1,4,6};
	int m=3;

	int i=n-1;
	int j=m-1;
	int k=n+m-1;
	while(i>=0 && j>=0){
		if(a[i]<=b[j]){
			a[k]=b[j];
			k--;
			j--;
		}
		else{
			a[k]=a[i];
			k--;
			i--;
		}
	}
	while(j>=0){
		a[k]=b[j];
		k--;
		j--;
	}
	for(int i=0;i<n+m;i++){
		cout<<a[i]<<" ";
	}
}