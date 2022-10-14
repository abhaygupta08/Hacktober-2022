class Solution {
public:
    int myAtoi(string s) {
        long long int ans=0;
        int sign=1;
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ') i++;
        if(i==n)return ans;
        if(s[i]=='+' || s[i]=='-')
        {
            sign= (s[i]=='+') ? 1 : -1;
            i++;
        }
        while(i<n && (s[i]>='0' && s[i]<='9'))
        {
            ans= ans*10 + (s[i]-'0');
            if(ans>=INT_MAX || ans<=INT_MIN)
                break;
            i++;
        }
        if(sign==-1) ans *=-1;
        if(ans>=INT_MAX)
            return INT_MAX;
        if(ans<=INT_MIN)
            return INT_MIN;
        return ans;
      
// BUILT-IN StringStream extracts the datatype elemnts that we want, eg string . int, dobule etc
        // stringstream ss(s);
        // int ans=0;
        // ss>>ans;
        // return ans;
        
    }
};
