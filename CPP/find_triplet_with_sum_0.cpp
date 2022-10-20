// Find triplets with sum 0

#include<iostream>
#include<bits/stdc++.h>

#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define repi(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
using namespace std;

void find_triplets(int arr[], int n)
{
	bool found = false;
	sort(arr,arr+n);
	rep(i,n-1){
		int l=i+1;
		int r=n-1;
		int x=arr[i];
		while (l < r) {
			if (x + arr[l] + arr[r] == 0) {
				cout<<" Triplets are ["<<x<<","<<arr[l]<<","<<arr[r]<<"]\n";
				l++;
				r--;
				found = true;
			}
			else if (x + arr[l] + arr[r] < 0) l++;
			else r--;
		}
	}

	if (found == false)
		cout << " No Triplet Found" << endl;
}

int main(){
	int n;
	cin>>n;
	int ar[n];
	rep(i,n){
		cin>>ar[i];
	}
	find_triplets(ar,n);
}

