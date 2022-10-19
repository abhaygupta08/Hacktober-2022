#include<bits/stdc++.h>
using namespace std;
int greaterthanorequal(int *arr,int n, int val){
    int lo=-1,hi=n;
    while(hi-lo>1){
     int mid=(hi+lo)/2;
     if(arr[mid]>=val){
        hi=mid;
     }
     else{
         lo=mid;
     }
    }
    return hi;
}
int lessthanorequal(int *arr, int n, int val){
    int lo=-1,hi=n;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(arr[mid]<=val){
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    return lo;
}
int fastsearch(int *arr,int n,int l, int r){
    int rightindex=greaterthanorequal(arr,n,l);
    int leftindex=lessthanorequal(arr,n,r);
    return rightindex-leftindex+1;
}
    int main(){
    int n,k,l,r;
    cin>>n;
    int arr[n];
    for(int i=0;i,n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cin>>k;
    while(k!=0){
        cin>>l>>r;
        int res=fastsearch(arr,n,l,r);
        cout<<res<<" ";
        k--;
    }
    return 0;
}