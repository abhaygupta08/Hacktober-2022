#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T!=0){
        int N,X,K,A[N],B[N],C,cnt=0;
        cin>>N>>X>>K;
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
            cin>>B[i];
        }
        for(int i=0;i<N;i++){
            if(A[i]>=B[i]){
                C=A[i]-B[i];
            }
            else{
                C=B[i]-A[i];
            }
            if(C<=K){
                cnt++;
            }}
            if(cnt<=K){
                cout<<"YES"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
            }
        
        T--;
    }
    return 0;
}