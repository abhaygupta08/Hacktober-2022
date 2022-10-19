#include<bits/stdc++.h>
using namespace std;
int main(){
int T,A,B,X;
cin>>T;
while(T!=0){
cin>>A>>B>>X; 
 int k=B-A;
 cout<<k/X<<'\n';   
    T--;
}
    return 0;
}