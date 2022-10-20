#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,A,B,C;
    cin>>t;
    while(t!=0){
    cin>>A>>B>>C;
    if(A>B && B>C || A<B && B<C ){
        cout<<B;
    }
    else if(A>C && A<B || A<C && A>B){
        cout<<A;
    }
    else{
        cout<<C;
    }
        t--;
    }
    return 0;
}