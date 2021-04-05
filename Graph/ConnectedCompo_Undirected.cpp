// Finding the number of connected component in the undirected graph

// The number of connected components in the graphs == no of dfs calls we make while visiting each connected-subgraph
// For in every DFS calls we visit all the nodes of a particular connected subgraphs, and since the subgraphs are not connected with each other(if compn>1) then
// we need to visit all nodes of each sub-graphs using DFS calls. thus no of dfs call==no of connected sub-graphs

#include<bits/stdc++.h>
using namespace std;
void dfs(int v, vector<bool>&visited,vector<int>adj[])
{
    visited[v]=true;

    for(auto neigh:adj[v])
    {
        if(visited[neigh]==false)
        {
            visited[neigh]=true;
            dfs(neigh,visited,adj);
        }

    }
}
int main()
{
    int V,E;   // v= no of vertices/nodes (1---n), E= no of Edges in an undirected graph
    cin>>V>>E;
    vector<int>adj[V+1];

    for(int i=0;i<E;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>visited(V+1,false);

   // no of connected components
   int cnt=0;
    for(int i=1;i<=V;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,adj);
            cnt++;
        }
    }
    cout<<cnt;

}