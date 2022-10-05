#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
	map<T,list<T>> neighbourMap;
	bool isDirected;

public:
	graph(bool isDirected=false){
		this->isDirected=isDirected;
	}

	void addEdge(T u, T v){
		neighbourMap[u].push_back(v);

		if(!isDirected){
			neighbourMap[v].push_back(u);
		}
	}




	bool dfsHelper(T source, unordered_set<T>&visited,T parent){
		visited.insert(source);
		list<T> neighbourList=neighbourMap[source];
		for(T neighbour:neighbourList){
			if(visited.find(neighbour)==visited.end()){
		       if(dfsHelper(neighbour,visited,source)){
		       	return true;
		       }
			}
			else{
				if(neighbour!=parent){
					return true;
				}
			}
		}
		return false;

	}

	bool isCyclePresent(){
		bool flag=false;
		unordered_set<T>visited;
		for(pair<T,list<T>> vertex:neighbourMap){
			T vertexLabel=vertex.first;
			if(visited.find(vertexLabel)==visited.end()){
				if(dfsHelper(vertexLabel,visited,vertexLabel)){
					flag=true;
					break;
				}
			}
		}
		return flag;
	}

};


int main(){
	graph<char>g;
	g.addEdge('A','B');
	g.addEdge('A','C');
	g.addEdge('B','C');

	g.isCyclePresent()?cout<<"FOUND":cout<<"NOT FOUND"<<endl;
	return 0;
}	
