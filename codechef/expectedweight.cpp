#include<bits/stdc++.h>
using namespace std;
#define double int;
int32_t main(){
    int T;
    cin>>T;
    while(T!=0){
        int n;
        cin>>n;
        if(n==1){
            cout<<"1";
        }
        else{
        int k=n-1;
        int l=n+1;
        int p=k*l*l*n*n/4;
                 int fac=1;
        while(n!=0){
            fac=fac*n;
            n=n-1; 
        }
        cout<<p/fac<<'\n';}
        T--;
    }
    return 0;
}