// Q163 https://leetcode.com/problems/is-graph-bipartite/

// other way of question: can the graph be coloured only using 2 colors with no adjacent nodes having same colors 

// Time: O(N+E)
// Space: Graph + rec stack + color array
        // O(N+E) + O(N) + O(N)

class Solution {
    bool bipartiteDFS(int node,vector<int> &col, vector<vector<int>>& g){
        if(col[node]==-1) col[node]=1;// making the 1st call the node is uncolored
        for(auto it: g[node]){
            if(col[it]==-1){
                col[it]=1-col[node];
                if(!bipartiteDFS(it,col,g)) return false;
            }
            else if(col[node]==col[it]) return false;
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!bipartiteDFS(i,col,g)){
                    return false;
                }
            }
        }
        return true;
    }
};


