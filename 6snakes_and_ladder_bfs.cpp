// by Kumari NEHAAAAAAAAAAAAAAAAAAAAAA
#include<bits/stdc++.h>
using namespace std;
//Given a snake and ladder board,
// find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. Basically, the player has total control over outcome of dice throw and
// wants to find out minimum number of throws required to reach last cell.

//same as finding the shortest path using BFS

template<typename T>
class Graph{
    map<T,list<T>> l;
public:
void addEdge(int x,int y){
    l[x].push_back(y);
}
void bfs(T src,T dest){
    map<T,int> dis;
    queue<T>q;
    for(auto node_pair:l){
    T node=node_pair.first;
    dis[node]=INT_MAX;
}
    q.push(src);
    dis[src]=0;

    
    while(!q.empty()){
        T node=q.front();
       // cout<<node<<" ";
        q.pop();
        for(auto nbr:l[node]){
            if(dis[nbr]==INT_MAX){
                q.push(nbr);
                dis[nbr]=dis[node]+1;
            }
        }
    }
        //path 
    cout<<"The path followed is:"<<endl;
    T temp=dest;
    while(temp!=src){
        cout<<temp<<"<--";
        temp=parent[temp];
    }
    cout<<src<<endl;
 cout<<"minimum no. of dice thrown is="<<dis[dest]<<endl;


}
};
int main(){
    int N;
    cin>>N;
    //n*n=N is the dimension of the board
int moves[N+1];
for (int i = 0; i<N+1; i++) 
        moves[i] = 0; 
      //Enter the snakes and ladders
    //and update the net move
    int m;cin>>m;
    //enter the number of moves
for(int i=0;i<m;i++){
int start,end;
cin>>start>>end;
moves[start]=end-start;
//in case of a snake moves[j] is a negative value
//in case of ladder moved[j] is a positive value
}
Graph<int> g;
//i is the current position 
//dice is the value on the dice throw
// j is the final position
// j is updated whenever there is snakes or ladder

//now add the edge (i,j) to the graph & run BFS on it

for(int i=0;i<=N;i++){
    for(int dice=1;dice<=6;dice++){
        int j=i+dice;
        j+=moves[j];
        if(j<=N){
         g.addEdge(i,j);
        }
    }
}
g.addEdge(N,N);
g.bfs(0,N);

return 0;
}
