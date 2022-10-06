// Q162 https://leetcode.com/problems/is-graph-bipartite/

// other way of question: can the graph be coloured only using 2 colors with no adjacent nodes having same colors 

// Time: O(N+E)
// Space: Graph + queue + color array
        // O(N+E) + O(N) + O(N)

class Solution {
    bool bipartiteBFS(int src,vector<int> &col, vector<vector<int>>& g){
        queue<int> q;
        q.push(src);
        col[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: g[node]){
                if(col[it]==-1){
                    col[it]=1-col[node];
                    q.push(it);
                }
                else if(col[node]==col[it]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!bipartiteBFS(i,col,g)){
                    return false;
                }
            }
        }
        return true;
    }
};

