#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T!=0){
        string str,str1;
        string a,b,c;
        cin>>a>>b>>c;
        string  x,y;
        cin>>x>>y;
        str=a+b+c;
        str1=x+y;
        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                if(str[i]==str1[j]){
                    cout<<str1[j]<<'\n';
                
                }
                break;
            }
        }
        
        T--;
    }
    return 0;
}