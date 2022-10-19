#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,k;
    cin>>N;
    if(N>=42){
        k=N+1;
    }
    else{
        k=N;
    }
    cout<<"AGC"<<setfill('0')<<setw(3)<<k;
    return 0;
}