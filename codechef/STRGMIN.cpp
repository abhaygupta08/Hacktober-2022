#include<bits/stdc++.h>
using namespace std;
#define long long int;
int32_t main(){
    int T;
    cin>>T;
    while(T!=0){
        int N;
        cin>>N;
        int arr[N];
        int p,q,k;
        for(int i=N+1;i<=2*N;i++){
        
          p=__gcd(N,i);
          q=N*i/p;
          if(p>q){
               k=p-q;
          }
          else{
              k=q-p;
          }
          arr[i]=k;
        }
        sort(arr+N+1,arr+2*N);
        int l=arr[N+1];
        for(int i=N+1;i<2*N;i++){
            if(l==k){
                cout<<i;
            }
        }


        T--;
    }
    return 0;
}