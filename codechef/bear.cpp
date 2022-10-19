#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int x;

    for(int x=1;x<100;x++){
        int A=pow(3,x);
        int B=pow(2,x);
        int r=(A*a)-(B*b);
        if(r>0){
            cout<<x;
            break;
        }
    }
    return 0;
}