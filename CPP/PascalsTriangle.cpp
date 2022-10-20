// https://leetcode.com/problems/pascals-triangle/submissions/

class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> r(n);
        // r.push_back({1});
        // if(n==1){
        //     return r;
        // }
        // r.push_back({1,1});
        // if(n==2){
        //     return r;
        // }
        for (int i = 0; i < n; i++)
        {
            r[i].resize(i + 1);
            r[i][0] = 1;
            r[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                int d = r[i - 1][j - 1] + r[i - 1][j];
                r[i][j] = d;
            }
        }
        return r;
    }
};
