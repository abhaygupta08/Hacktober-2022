// Can only be applied on DAG
//DAG: Directed Acyclic Graph

//Using DFS


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

stack<int> s;
void topoSort(unordered_map<int, vector<int>> adjList, int n, int m, int node){
int val= node;
visited[val]= 1;

// parent[node]=-1;
for(auto it: adjList[val]){
    if(!visited[it]){
        topoSort(adjList, n, m, it);
   
}
// cout<<endl;
 
// cout<<s.top()<<" ";
}
s.push(val);
}

int main(){
    int n, m;
    bool direction;
    cout<<"Enter nodes, edges, & direction:";
    cin>>n>>m>>direction;
    createAdjList(n, m, direction);
    // printAdjList();
    int node=1;
    topoSort(adjList, n, m, node);
    int f= s.size();
    cout<<"TOPOLOGICAL SORT IS: ";
    for(int i=0; i<f; i++){
        cout<<s.top()<<" ";
        s.pop();

    }
}
