#include<iostream>
using namespace std;
int main()
{
	int a[]={10,20,30,40};
	int n=sizeof(a)/sizeof(int);

	//iterate over all the possible starting indices
	for(int i=0;i<n;i++){
	//iterate over all the possible ending indices
		for(int j=i;j<n;j++){
	//cout<<i<<" "<<j<<" "<<endl;
			for(int k=i;k<=j;k++){
				cout<<a[k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
}
