#include<bits/stdc++.h>
using namespace std;
int sum(int n){
    int p=n*(n+1)/2;
    return p;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,d;
        cin>>d>>n;
        for(int i=0;i<d;i++){
            n=sum(n);
        }
        cout<<n<<'\n';
    }
    return 0;
}