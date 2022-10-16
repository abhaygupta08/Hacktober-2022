#include<iostream>
using namespace std;
int main()
{
	int A[5]={10,20,30,50,20}; //constraints 1 to 100
	// int n;
	 // cin>>n;
	int i=0;
	int j=4; //j=n-1
	
	while(i<j)  //i will increase when swapping will done
	{
		// int temp=A[i];
		// A[i]=A[4-i];
		// A[4-i]=temp;
		swap(A[i],A[j]);
		i++;j--;
	}
	for(int i=0;i<5;i++)
	{
		cout<<A[i]<<" ";
	}

}