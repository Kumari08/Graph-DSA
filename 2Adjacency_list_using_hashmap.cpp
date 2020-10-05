#include<bits/stdc++.h>
using namespace std;
//adjaceny list using hash_map byyyyyyyyyy NEHAAAAAAAAAAAAAA 
//WEIGHTED GRAPH

class Graph{
    int V;
    //unordered map//adjacency list
    unordered_map<string,list<pair<string,int>>> l;
public:
void addEdge (string x,string y,bool bidi,int wt){
l[x].push_back(make_pair(y,wt));
 if(bidi)
  l[y].push_back(make_pair(x,wt));
}
void printlist(){
    //iterate over all the keys in the map
    for(auto p : l){
        string city=p.first;
        list<pair<string,int>> nbrs=p.second;
        cout<< city<<"->";
        for(auto  nbr: nbrs)
        {
            string dest=nbr.first;
            int dist=nbr.second;
            cout<<dest<<" "<<dist<<",";
        }
        cout<<"end"<<endl;
    }
}
};


int main(){
    Graph g;
    g.addEdge("A","B",true,20); 
    g.addEdge("B","D",true,10);
    g.addEdge("A","C",false,40);
    g.addEdge("B","C",true,10);
    g.addEdge("A","D",true,5);
    g.addEdge("C","D",false,20);

   
    g.printlist();
    return 0;
}
