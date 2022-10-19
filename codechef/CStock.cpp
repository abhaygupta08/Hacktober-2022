#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T!=0){
        float S,A,B,C,hi;
        cin>>S>>A>>B>>C;
         hi=S+(C*S/100);
         if(hi>=A && hi<=B){
             cout<<"YES"<<'\n';
         }
         else{
             cout<<"NO"<<'\n';
         }
        T--;
    }
    return 0;
}