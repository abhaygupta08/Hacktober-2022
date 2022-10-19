#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int arr[7];
        for(int i=0;i<7;i++){
            cin>>arr[i];
        }
        sort(arr,arr+7);
        cout<<arr[3]-arr[0]<<" "<<arr[6]-arr[1]-arr[2]<<" "<<arr[4]-arr[0]<<'\n';

    }
    return 0;
}