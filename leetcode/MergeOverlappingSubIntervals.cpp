// https://leetcode.com/problems/merge-intervals/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &in)
    {
        vector<vector<int>> res;
        if (in.size() == 0)
        {
            return in;
        }
        sort(in.begin(), in.end());
        vector<int> ti = in[0];
        for (auto i : in)
        {
            if (i[0] <= ti[1])
            {
                ti[1] = max(ti[1], i[1]);
            }
            else
            {
                res.push_back(ti);
                ti = i;
            }
        }
        res.push_back(ti);

        return res;
    }
};

// edgecases does not work
//  class Solution {
//  public:
//      vector<vector<int>> merge(vector<vector<int>>& in) {
//          vector<vector<int>> res(in.size(), vector<int> (in[0].size()));
//  if(in.size()==0){
//      return in;
//  }
//          sort(in.begin(),in.end());
//          res[0][0]=in[0][0];
//          int z=0;
//          for(int i=1;i<in.size();i++){
//              // for(int j=0;j<2;j++){
//                  if(in[i][0]<=in[i-1][1]){
//                      continue;
//                  }
//                  else{
//                      res[z][1]=in[i-1][1];
//                      z++;
//                      res[z][0]=in[i][0];
//                  }
//              // }
//          }
//          res[z][1]=in[in.size()-1][1];
//          res.resize(z+1);
//          return res;
//      }
//  };
