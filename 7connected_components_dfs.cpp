// by Kumari NEHAAAAAAAAAAAAAAAAAAAAAA
#include<bits/stdc++.h>
using namespace std;
//Depth First Search
//The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and 
//explores as far as possible along each branch before backtracking.

//Connected components using DFS graphs 
//how many connected components are present
template<typename T>
class Graph{
    map<T,list<T>> l;
public:
void addEdge(int x,int y){
    l[x].push_back(y);
    l[y].push_back(x);
}
void dfs_helper(T src,map<T,bool> &visited){
    //Recursive function that will travel the graph
    cout<<src<<" ";
    visited[src]=true;
//go to every neighbors that is not visited
for(T nbr:l[src])
{
    if(!visited[nbr]){
        dfs_helper(nbr,visited);
    }
}
}
void dfs(){
    map<T,bool> visited;
    for(auto node_pair:l){
    T node=node_pair.first;
    visited[node]=false;
}
//call the helper function
//iterate over  all the vertices & call dfs helper
    int cnt=0;

for(auto node_pair:l){
    T node=node_pair.first;
    if(!visited[node]){
        cout<<"Component "<<cnt<<"-->";
    dfs_helper(node,visited);    
    cout<<endl;
    cnt++;

    }
}
}
};
int main(){
    
Graph<int> g;
g.addEdge(1,2);
g.addEdge(0,1);
g.addEdge(2,3);
g.addEdge(0,4);
g.addEdge(0,3);
g.addEdge(5,6);
g.addEdge(6,7);
g.addEdge(8,8);
g.dfs();

return 0;
}
