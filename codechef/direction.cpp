#include<bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin>>T;
  while(T!=0){
    int n;
    cin>>n;
    for(int i>=0;i<=1000;i++){
        if(n==1+4*i){
            cout<<"East";
            break;
        }
        else if(n==3+4*i){
            cout<<"West";
            break;
        }
        else if(n==2+4*i){
            cout<<"North";
            break;
        }
        else{
            cout<<"South";
            break;
        }
    }


      T--;
  }


    return 0;
}