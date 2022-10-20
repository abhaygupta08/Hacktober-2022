class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        n=n-1;
        while(n--)
        {
            int count=1,i=0;
            string temp="";
            while(ans[i]!='\0')
            {
                count =1;
                while(ans[i]==ans[i+1])
                {
                    count++;
                    i++;
                }
                temp.append(to_string(count)+ans[i]);
                i++;
            }
            ans=temp;
        }
        return ans;
    }
};
