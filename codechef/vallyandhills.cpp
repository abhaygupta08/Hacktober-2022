#include<iostream>
#include<string>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M;
         string s;
        cin>>N,M;
        if(N>M){
            N=N-M;
            while(M!=0){
            s+="01";
            M--;
            }
            while(N!=0){
                s+="010";
                N--;
            }
        }
        else if(M>N){
            M=M-N;
            while(N!=0){
                s+="10";
                N--;
            }
            while(M!=0){
                s+="101";
                M--;
            }
          
        }
        else{
            while(N+1!=0){
                s+="01";
                N--;
            }
        }
        cout<<s.size()<<'\n';
        cout<<s<<'\n';
    }
    return 0;
}