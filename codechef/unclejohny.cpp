#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>k;
        int r=arr[k-1];
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            if(arr[i]==r){
                cout<<i+1<<'\n';
            }
        }
    }
    return 0;
}