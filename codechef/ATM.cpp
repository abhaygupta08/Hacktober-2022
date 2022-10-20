#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    float y;
    cin>>x>>y;
    if(x%5!=0 && x+0.5<y){
        cout<<fixed<<setprecision(2 )<<y;
    }
    else if(x>y){
        cout<<fixed<<setprecision(2)<<y;
    }
    else{
        float d=y-x-0.50;
        cout<<fixed<<setprecision(2);
        cout<<d;
    }
    return 0;
}