#include<bits/stdc++.h>
using namespace std;
int getcloseleft(int *arr,int n,int val){
    int lo=-1,hi=n;
    while(hi-lo>1){
        int mid=(lo+hi)>>1;
        if(arr[mid]>=val){
            hi=mid;
        }
        else{
            lo=mid;
        }
    }
    return hi;
}
int main(){
    int n,k,val;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(k!=0){
        int val;
        cin>>val;
        cout<<getcloseleft(arr,n,val)+1<<'\n';
        k--;
    }
    
    return 0;
}