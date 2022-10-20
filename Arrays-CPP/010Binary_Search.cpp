#include<iostream>
using namespace std;
int main()
{
	int a[]={10,20,30,40};
	int n=sizeof(a)/sizeof(int);
	int t=30;
	int s=0;
	int e=n-1;
	while(s<=e){
	 int mid=(s+e)/2;
	 if(a[mid]==t){
	 	//you have found the target at index mid
	 	cout<<"target found at"<<mid;
	 	break;  //to stop the loop
	 }
	 else if(a[mid]>t)
	 {
	 	//reduce your search space from [s,e] to [s,mid-1]
	 	e=mid-1;
	 }
	  else
	 {
	 	//reduce your search space from [s,e] to [mid+1,e]
	 	s=mid+1;
	 }
	}
	return 0;
}