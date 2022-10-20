// Q154 https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(E+V)  //DFS
// Space: O(E+V)+O(V)+O(V)   
#include<bits/stdc++.h>
vector<int> BFS(int v, vector<pair<int, int>> edge){
    int e=edge.size();
    vector<int> bfs;
    vector<int> vis(v,0);
    vector<int> adj[v]; //vector of arrays
    for(int i=0;i<e;i++){
        adj[edge[i].second].push_back(edge[i].first);
        adj[edge[i].first].push_back(edge[i].second);
    }
    for(int i=0;i<v;i++){
        if(!vis[i]){ 
            queue<int> q;
            q.push(i);
            vis[i]=1;
            sort(adj[i].begin(),adj[i].end());
            while(!q.empty()){
                int node=q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it:adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
    return bfs;
}

