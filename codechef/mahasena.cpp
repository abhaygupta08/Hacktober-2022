#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,sum=0,p=0;
    int arr[N];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int j=0;j<N;j++){
        if(arr[j]%2==0){
       sum=sum+1;
        }
        else{
            p=p+1;
        }
    }
    if(sum>p){
        cout<<"READY FOR BATTLE";
    }
    else{
        cout<<"NOT READY";
    }
    return 0;
}