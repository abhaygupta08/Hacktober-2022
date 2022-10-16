//bubble sort

#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int A[5]={10,20,-30,50,-20};

	int n=5;
	for(int i=1;i<n;i++)
	{
		//in the ith pass place the largest element of 
		//unsorted part of array to correct pos

		bool flag=false; //assume no swap will done
		for(int j=0;j<n-i;j++)
		{
			if(	A[j]>A[j+1])
				{swap(A[j],A[j+1]);
				flag=true;}
		}
		if(!flag) //flag==false
			break; //array is sorted

		
	}
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}
