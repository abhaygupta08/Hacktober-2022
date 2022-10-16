#include<iostream>
using namespace std;
int main()
{
	int a[]={50,40,10,30,20};
	int n=sizeof(a)/sizeof(int);

	for(int i=1;i<n;i++){
		int key=a[i];
		//insert the key to its correct posn in 
		//the sorted part of an array that starts from 
		//index i-1

		int j=i-1;
		while(j>=0 and key<a[j]){
			a[j+1]=a[j];
			j--;
		} 
		a[j+1]=key;
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
return 0;
}