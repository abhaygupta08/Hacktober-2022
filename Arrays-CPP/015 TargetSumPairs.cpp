#include<iostream>
using namespace std;
int main(){
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			cout<<a[i]<<","<<a[j]<<" ";
		}
		cout<<endl;
	}
}