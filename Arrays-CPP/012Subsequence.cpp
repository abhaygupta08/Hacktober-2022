// FIND SUBSEQUENCE IN AN ARRAY !

#include<iostream>
using namespace std;
int main()
{
	int a[]={10,20,30};
	int n=sizeof(a)/sizeof(int);
	//iterate over number from 0 to 2^n-1
	for(int num=0;num<(1<<n); num++){  //0<<n 2^n
		for(int i=0;i<n;i++){
			if((num>>i)&1){        //ith bit set 
				cout<< a[i] <<" ";
			}

		}
		cout<<endl;
	}
	return 0;
}

// num is the number of binary number like for 3 it is 8{0 to 7} 2^3
//to iterate every bit.