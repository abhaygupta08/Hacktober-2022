#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
cin>>T;
while(T!=0){
    int n;
    cin>>n;
    int sum=0;
    while(n!=0){
    if(n%10==4){
        sum=sum+1;
    }
    n=n/10;}
    cout<<sum<<'\n';
    T--;
}
    return 0;
}