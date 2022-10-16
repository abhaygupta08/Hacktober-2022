#include<iostream>
using namespace std;
int main()
{
	int A[100]; //constraints 1 to 100
	int n;
	cin>>n;
	int j;  //target 
	cin>>j;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int i;
	// for(i=0;i<n;i++)
	// {
	// 	if(A[i]==j)
	// 		{
	// 			cout<<i;
	// 			break;
	// 		}

	// }
	// if(i==n) //if number not found
	// {
	// 	cout<<"not found";
	// }
 
	for(i=n-1;i>=0;i--)  //last occurence
	{
		if(A[i]==j)
			{
				cout<<i;
				break;
			}
	}
	
	if(i==-1) //if j  not found from back 
	{
 		cout<<"not found";
	}
	return 0;
}