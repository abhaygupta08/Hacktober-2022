#include<iostream>
using namespace std;
int main(){
	int arr[] = {2, 3, 2, 4, 0, 2, 0};
	int n = sizeof(arr) / sizeof(int);
	int k = 6;

	int wSum=0;
	int maxlen=-1;
	int i=0 , j=0;
	while(j<n){
		wSum+=arr[j];
		if(wSum == k){
			// can be soln
			maxlen=max(maxlen,j-i+1);
		}
		if(wSum > k){
			// now we have to optimize length
			while(wSum > k){
				wSum -= arr[i];
				i++;
			}
		}
		j++;
	}
	cout<<maxlen;
	return 0;
}