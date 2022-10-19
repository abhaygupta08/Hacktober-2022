#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
      int  diff=arr[1]-arr[0];
        for(int i=0;i<n;i++){
            int s=arr[i+1]-arr[i];
            diff=min(s,diff);
        }
        cout<<diff<<'\n';
    }
    return 0;
}