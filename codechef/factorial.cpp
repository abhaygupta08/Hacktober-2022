#include<bits/stdc++.h>
using namespace std;
#define double int;
int32_t main(){
    int t,n,fac;
    cin>>t;
    while(t!=0){
        cin>>n;
        fac=1;
        while(n!=0){
            fac=fac*n;
            n=n-1;
           
        }
        t--;
         cout<<fac<<'\n';
    }
    return 0;
}