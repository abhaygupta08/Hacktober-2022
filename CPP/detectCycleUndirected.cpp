#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adjList;
unordered_map<int, bool> visited;
unordered_map<int, int> parent;
void createAdjList(int n, int m, bool direction){
for(int i=0; i<m; i++){
    cout<<"Enter Edge #"<<i+1<<": ";
    int u, v;
    cin>>u>>v;
    adjList[u].push_back(v);
    if(!direction)
    adjList[v].push_back(u);
}
}
void printAdjList(){
for(auto it: adjList){
    cout<<it.first<<"-> ";
    for(auto i: it.second){
        cout<<i<<", ";
    }
    cout<<endl;
}
}
bool checkCycle(unordered_map<int, vector<int>>adjList, unordered_map<int, int> parent, int n, int m, int node){
    queue<int> q;

    int val= node;
    q.push(val);
    visited[val]= 1;
    parent[val] =-1;
    while(!q.empty()){
      val= q.front();
      q.pop();
    for(auto it: parent) cout<<it.first<<"->"<<it.second<<endl;
      for(auto it: adjList[val]) {
         if(visited[it] && parent[it]!=val){
            return 1;
         }
         else{
            visited[it]=1;
            parent[it]= val;
            q.push(it);
         }

      }

    }
    return 0;
}

int main(){
    int n, m;
    bool direction=0;
    cout<<"Enter nodes, edges, & direction:";
    cin>>n>>m>>direction;
    createAdjList(n, m, direction);
    // printAdjList();
    int node=4;
    cout<<checkCycle(adjList, parent, n, m, 1);
}