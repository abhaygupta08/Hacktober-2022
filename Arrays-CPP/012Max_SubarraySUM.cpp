#include<iostream>
#include<climits>  // INT_MIN
using namespace std;
int main()
{
	int a[]={-10,8,3,-2};
	int n=sizeof(a)/sizeof(int);
	int mx=INT_MIN;


	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=0;
			for(int k=i;k<=j;k++){	
				sum+=a[k];
			}
			mx=max(mx,sum);
		}
	}
	cout<<mx;

}