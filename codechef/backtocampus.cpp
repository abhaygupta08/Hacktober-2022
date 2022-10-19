#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T!=0){
        int N,K;
        cin>>N>>K;
        int P=N/K;
       int Q=N%K;
        if(Q==0){
            cout<<P<<'\n';
        }
        else{
        cout<<P+1<<'\n';}
        T--;
    }
    return 0;
}