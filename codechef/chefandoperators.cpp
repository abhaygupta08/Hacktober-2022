#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,A,B;
    cin>>t;
    while (t!=0)
    {
        cin>>A>>B;
        if(A==B){
            cout<<"=";
        }
        else if(A>B){
            cout<<">";
        }
        else{
            cout<<"<";
        }
        t--;
    }
    
    return 0;
}