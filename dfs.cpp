// by Kumari NEHAAAAAAAAAAAAAAAAAAAAAA
#include<bits/stdc++.h>
using namespace std;
//Depth First Search
//The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and 
//explores as far as possible along each branch before backtracking.

//recursive approach

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
void dfs(T src){
    map<T,bool> visited;
    for(auto node_pair:l){
    T node=node_pair.first;
    visited[node]=false;
}
//call the helper function
dfs_helper(src,visited);    
}
};
int main(){
    
Graph<int> g;
g.addEdge(1,2);
g.addEdge(0,1);
g.addEdge(2,3);
g.addEdge(3,4);
g.dfs(0);

return 0;
}
