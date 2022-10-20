#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int X,Y,P,Q;
        cin>>X>>Y>>P>>Q;
        int k=X+10*P;
        int l=Y+10*Q;
        if(k>l){
            cout<<"Chefina";
        }
        else if(k==l){
            cout<<"Draw";
        }
        else{
            cout<<"Chef";
        }
    }
    return 0;
}