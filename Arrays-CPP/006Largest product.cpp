#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int A[5]={10,20,-30,50,-20}; //constraints 1 to 100
	// int n;
	 // cin>>n;
	int fl=INT_MIN;
	int sl=INT_MIN;
	int tl=INT_MIN;

	int fs=INT_MAX;
	int ss=INT_MAX;
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
	for(int i=0;i<5;i++)
	{	
		if(A[i]<fs)
		{
			ss=fs;
			fs=A[i];
		}
		else if(A[i]<ss)
		{
			ss=A[i];
		}

}
int p1,p2;
p1=fl*sl*tl; 
p2=ss*fs*fl; //-20,-30,40
// if(p1>p2)
// {
// 	cout<<p1;
// }
// else
// cout<<p2;
cout<<max(p1,p2);  //max(fl*sl*tl , fl*ss*fs);
}