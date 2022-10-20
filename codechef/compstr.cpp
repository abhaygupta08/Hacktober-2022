#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T!=0){
        int N;
        cin>>N;
        string A,B;
        cin>>A;
        cin>>B;
        int count=0;
        for(int i=0;i<N;i++){
            if(A[i]<=B[i]){
                count++;
            }
        }
        cout<<count<<'\n';

        T--;
    }
    return 0;
}