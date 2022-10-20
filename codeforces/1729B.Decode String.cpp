#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string ans="";
        int val=0;
        for(int i=n-1;i>=0;)
        {
            if(s[i]=='0')
            {
                val=(s[i-2]-48)*10+s[i-1]-48;
                i-=3;
            }
            else {
                val=s[i]-48;
                i--;
            }
            ans+=char(val+97-1);
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}
