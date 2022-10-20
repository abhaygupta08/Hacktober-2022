class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sum=0, ans=0;
        sum+= amount[0]+amount[1]+amount[2];
        sort(amount.begin(), amount.end(), greater<int>());
        while(sum!= amount[0] || sum){
        if(amount[0] == 0 || amount[1]==0)
            break;
            int sum=0;
            ans+=1;
        amount[0]-=1;
        amount[1]-=1;
        sum= amount[0]+amount[1]+amount[2];
        sort(amount.begin(), amount.end(), greater<int>());
        }
        ans+= amount[0];
        return ans;
    }
};
