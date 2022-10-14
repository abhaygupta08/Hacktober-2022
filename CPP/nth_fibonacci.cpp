#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;
 map<int, int> m;

int f(int n)
{

    if(m.count(n))  return m[n];

    int k = n/2;

    if(n%2==0)
    {
        return m[n] = (f(k)*f(k)+f(k-1)*f(k-1))%mod;
    }
    else{
       
       return m[n]= (f(k)*f(k+1)+ f(k)*f(k-1))%mod;

    }

}

int32_t main() {

int n;

cin>>n;

m[0]=m[1]=1;

cout<<f(n)<<endl;


return 0;

}
