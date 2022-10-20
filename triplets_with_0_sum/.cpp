
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            int a=i+1, b=n-1;
            while(a<b)
            {
                int s=arr[a]+arr[b]+arr[i];
                
                if(s<0)
                  a++;
                  
               else
                  if(s>0)
                  b--;
                  else
                  return 1;
            }
        }
        return 0;
    }
};

int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
} 
