#include<iostream>
using namespace std;
int main()
{
	int A[100]={10,20,30,50,20}; //constraints 1 to 100
	// int n;
	// cin>>n;
	int j=40;  //target 
	
	bool flag=false;// assume target not present
	for(int i=0;i<4;i++)
	{
		if(A[i]==j)
		{
			cout<<i;
			flag=true;
		}
	}
	if(flag==false)
		cout<<"-1";
	
	
}