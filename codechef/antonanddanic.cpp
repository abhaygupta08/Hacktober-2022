#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,A=0,D=0;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i++){
        if(str[i]=='A'){
            A++;
        }
        else{
            D++;
        }
    }
    if(A>D){
        cout<<"Anton";
    }
    else if(A==D){
        cout<<"Friendship";
    }
    else{
        cout<<"Danik";
    }
    return 0;
}