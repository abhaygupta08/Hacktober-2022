#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,n,A,B;
    cin>>T;
    while(T!=0){
        int sum=0;
    cin>>n>>A>>B;
    string str;
    cin>>str;
    for(int i=0;i<n;i++){
        char c= 1;
        char d= 0;
        if(str[i]==c){
            sum=sum+1;
        }
    }
    int k=n-sum;
    cout<<(A*k)+(sum*B)<<'\n';
        T--;
    }
    return 0;
}