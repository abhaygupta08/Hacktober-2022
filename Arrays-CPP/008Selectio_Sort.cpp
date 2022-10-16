#include<iostream>
using namespace std;
int main()
{
	int a[]={50,40,30,10};
	int n=sizeof(a)/sizeof(int);

	for(int i=0;i<n-1;i++){
		//in the ith pass,we place the smallest element in the
		//unsorted part of array to its correct posn

		int min_idx=i;
		for(int j=i+1; j<n ;j++){
			if(a[j]<a[min_idx])
				min_idx=j;
		}

		swap(a[i],a[min_idx]);
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

}