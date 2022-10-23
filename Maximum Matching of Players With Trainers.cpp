class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int j=0,ans=0;
        for(int i=0;i<players.size()&&j<trainers.size();i++)
        {
               int need=players[i];
            while(trainers[j]<need)
            {
                j++;
                if(j==trainers.size())
                {
                    return ans;
                }
            }
            if(trainers[j]>=need)
            {
                ans++;
                j++;
            }

        }
        return ans;
    }
};
