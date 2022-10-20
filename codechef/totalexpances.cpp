#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int q,p;
        cin>>q>>p;
        double pay;
        if(q<1200){
            pay=p*q;
        }
        else{
            pay=p*q;
            pay=0.9*pay;
        }
        cout<<fixed<<std::setprecision(5)<<pay<<'\n';
    }
    return 0;
}