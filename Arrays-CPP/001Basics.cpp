#include<iostream>
using namespace std;
int main()
{
	int a[10];
	cout<<sizeof(a)<<endl; //4*10=40bytes
	cout<<a[2]; //garbage value
	cout<<endl;
	
	int n=sizeof(a)/sizeof(a[0]); //tells the size of array!!!
	
	cout<<n;
}