#include<iostream>
#include<map>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T!=0){
        int n,sum=0,high=-1;
        cin>>n;
        map<int,int>st;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            st[temp]++;
        }
        for(auto x: st){
          if(high<x.second) high=x.second;
          sum+=x.second;
        }
        if(high==n) cout<<"0"<<'\n';
        else if(high<=1 && n>=2) cout<<"-1"<<'\n';
        else cout<<(sum-high+1)<<'\n';
        T--;
    }
    return 0;
}