#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,n;
    cin>>T;
    while(T!=0){
        cin>>n;
        if(n<10){
            cout<<"Thanks for helping Chef!";
        }
        else{
            cout<<"-1";
        }
        T--;
    }
    return 0;
}