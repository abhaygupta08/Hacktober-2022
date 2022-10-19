#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T!=0){
        int N,K;
        cin>>N>>K;
        if(N%K==0){
            cout<<N/K;
        }
        else{
            cout<<"-1";
        }
        T--;
    }
    return 0;
}