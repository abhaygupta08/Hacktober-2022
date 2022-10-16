#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int A[5]={10,20,30,50,20}; //constraints 1 to 100
	// int n;
	 // cin>>n;
	int fl=INT_MIN;
	int sl=INT_MIN;
	int tl=INT_MIN;
	for(int i=0;i<5;i++)
	{	
		if(A[i]>fl)
		{
			tl=sl;
			sl=fl;
			fl=A[i];
		}
		else if(A[i]>sl)
		{
			tl=sl;
			sl=A[i];
		}
		else if(A[i]>tl)
		{
			tl=A[i];
		}

	}
	cout<<fl<<" "<<sl<<" "<<tl;


}
