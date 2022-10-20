//constraints : n<=100


#include<iostream>
#include<climits>  // INT_MIN
using namespace std;
int main()
{
	int a[]={10,20,30};
	int n=sizeof(a)/sizeof(int);

	int cSum[101]={};
	cSum[0]=0;
	for(int i=1;i<=n;i++){
		cSum[i]=cSum[i-1]+a[i-1];
	}
	
	// for(int i=0;i<=n;i++){
	// 	cout<<cSum[i]<<" ";
	// }
	int mx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int sum=cSum[j+1]-cSum[i];  //formula to find the max sum
			mx=max(sum,mx);
		}
	}
	cout<<mx;
}