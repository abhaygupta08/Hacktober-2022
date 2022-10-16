#include<iostream>
using namespace std;
int main(){
	int arr[] = {2, 3, 2, 4, 0, 2, 0};
	int n = sizeof(arr) / sizeof(int);
	int sum = 6;
	int len=0;
	int i=0, j=0;
	int currS=0;
	while(j<n){
		currS+=arr[j];
		while(currS>sum){
			currS-=arr[i];
			i++;
		}
		if(currS==sum){
			len=max(len,j-i+1);
		}
		j++;
	}
	cout<<len;
	return 0;
}