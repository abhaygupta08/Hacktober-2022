#include <iostream>
#include <list>
using namespace std;
//graph class for DFS traversal
class DFSGraph
{
int V;    // No. of vertices
list<int> *adjList;    // adjacency list
void DFS_util(int v, bool visited[]);  // A function used by DFS
public:
    // class Constructor
DFSGraph(int V)
    {
 this->V = V;
 adjList = new list<int>[V];
    }
    // function to add an edge to graph
void addEdge(int v, int w){
adjList[v].push_back(w); // Add w to v’s list.
    }

void DFS();    // DFS traversal function
};
void DFSGraph::DFS_util(int v, bool visited[])
{
    // current node v is visited
visited[v] = true;
cout << v << " ";

    // recursively process all the adjacent vertices of the node
list<int>::iterator i;
for(i = adjList[v].begin(); i != adjList[v].end(); ++i)
if(!visited[*i])
DFS_util(*i, visited);
}

// DFS traversal
void DFSGraph::DFS()
{
    // initially none of the vertices are visited
bool *visited = new bool[V];
for (int i = 0; i < V; i++)
visited[i] = false;

    // explore the vertices one by one by recursively calling  DFS_util
for (int i = 0; i < V; i++)
if (visited[i] == false)
DFS_util(i, visited);
}

int main()
{
    // Create a graph
DFSGraph gdfs(5);
gdfs.addEdge(0, 1);
gdfs.addEdge(0, 2);
gdfs.addEdge(0, 3);
gdfs.addEdge(1, 2);
gdfs.addEdge(2, 4);
gdfs.addEdge(3, 3);
gdfs.addEdge(4, 4);

cout << "Depth-first traversal for the given graph:"<<endl;
gdfs.DFS();

return 0;
}
/*
Iterative DFS
#include<bits/stdc++.h>
using namespace std;

// graph class
class Graph
{
int V;    // No. of vertices
list<int> *adjList;    // adjacency lists
public:
Graph(int V)  //graph Constructor
    {
this->V = V;
adjList = new list<int>[V];
    }
void addEdge(int v, int w) // add an edge to graph
    {
adjList[v].push_back(w); // Add w to v’s list.
    }
void DFS();  // DFS traversal

    // utility function called by DFS
void DFSUtil(int s, vector<bool> &visited);
};

//traverses all not visited vertices reachable from start node s
void Graph::DFSUtil(int s, vector<bool> &visited)
{
    // stack for DFS
stack<int> dfsstack;
   // current source node inside stack
dfsstack.push(s);

while (!dfsstack.empty())
    {
        // Pop a vertex
        s = dfsstack.top();
       dfsstack.pop();

        // display the item or node only if its not visited
 if (!visited[s])
        {
cout << s << " ";
visited[s] = true;
        }

        // explore all adjacent vertices of popped vertex.
        //Push the vertex to the stack if still not visited
for (auto i = adjList[s].begin(); i != adjList[s].end(); ++i)
if (!visited[*i])
dfsstack.push(*i);
    }
}
// DFS
void Graph::DFS()
{
    // initially all vertices are not visited
vector<bool> visited(V, false);

for (int i = 0; i < V; i++)
if (!visited[i])
DFSUtil(i, visited);
}

//main program
int main()
{
    Graph gidfs(5);  //create graph
gidfs.addEdge(0, 1);
gidfs.addEdge(0, 2);
gidfs.addEdge(0, 3);
gidfs.addEdge(1, 2);
gidfs.addEdge(2, 4);
gidfs.addEdge(3, 3);
gidfs.addEdge(4, 4);

cout << "Output of Iterative Depth-first traversal:\n";
gidfs.DFS();

return 0;
}
*/
