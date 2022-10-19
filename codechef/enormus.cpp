#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,num,sum=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
    cin>>num;
    if(num%k==0){
        sum=sum+1;
    }
    }
    cout<<sum;
    return 0;
}