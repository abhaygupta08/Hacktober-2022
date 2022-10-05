// Q166 https://www.codingninjas.com/codestudio/problems/2041977?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

//MUST WATCH algo drawbacks and advantages
// https://www.youtube.com/watch?v=75yC1vbS8S8&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29&ab_channel=takeUforward

// Time: O((N-1)*E)
// Space: O(N)

// Dikstra fails for the negative paths
// Bellman Ford fails only for the negative cycle  https://youtu.be/75yC1vbS8S8?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&t=81


#include<bits/stdc++.h>
int bellmonFord(int v, int e, int src, int dest, vector<vector<int>> &edge) {
   vector<int> dist(v+1,1e9);
    dist[src]=0;
    for(int i=1;i<=v-1;i++){
        for(auto it: edge){
//             if(dist[it[0]]+it[2]<dist[it[1]]){
//                 dist[it[1]]=dist[it[0]]+it[2];
//             }
            int u = it[0];
            int v = it[1];
            int w = it[2];
            int W = dist[u] == 1e9 ? 1e9 : w + dist[u];
            dist[v] = min(dist[v], W);
        }
    }
    return dist[dest];
}
