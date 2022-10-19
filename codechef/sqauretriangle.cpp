#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int m=n-2;
        m=floor(m/2);
        cout<<m*(m+1)/2<<'\n';
    }
    return 0;
}