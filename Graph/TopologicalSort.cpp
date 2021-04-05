// Topological sorting is only possible in the directed acyclic graphs (DAG) because there exist relations between the node 
// Topological sorting can be a non-unique and thus can have multiple permutation(topological) of the graph

// DFS implementation is used where the Exit time of the DFS calls are taken under consideration.
// The exit time of dfs(v) is always greater than the exit time of all the related vertex reachable from it dfs(adj of v) thus 
// it is pushed back at last on the stack/ vector and thus after each and every dfs calls we push the v at the last
// TC.= O(v+e)

// Assuming the graph is directed and acyclic 

// Global Declaration for the convenience
#include<bits/stdc++.h>
using namespace std;
 vector<bool>visited;
 stack<int>ans;
 void dfs(int v,vector<int>adj[])
 {
     visited[v]=true;

     for(auto neighbor:adj[v])
     {
       if(!visited[neighbor])
       {
           visited[neighbor]=true;
           dfs(neighbor,adj);
       }
     }
     ans.push(v);
 }
void topological_sort(int V,vector<int>adj[])
{
    visited.assign(V,false);

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj);
        }
    }

    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
}
int main()
{
   int V; cin>>V;
    vector<int>adj[V];
    for(int i=0;i<V;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    topological_sort(V,adj);
}