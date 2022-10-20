#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T!=0){
        int x,y,K;
        cin>>x>>y>>K;
        if(x%K==0 && y%K==0){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
        T--;
    }
    return 0;
}