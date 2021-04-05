#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

void dfs(int v, vector<int>adj[], vector<bool>&visited,stack<int>&stk)
{
    visited[v]=true;
    
    for(auto it:adj[v])
    {
        if(!visited[it])
            dfs(it,adj,visited,stk);
    }
    stk.push(v);
}

void dfs2(int x, vector<bool>&visited2,vector<int>adj2[])
{
    visited2[x]=true;
    
    for(auto it1:adj2[x])
    {
        if(!visited2[it1])
            dfs2(it1,visited2,adj2);
    }
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    
    // creating transpose matrix for the SCC
    vector<int>adj2[V];
    
    for(int i=0;i<V;i++)
    {
       for(auto x:adj[i])
       {
         adj2[x].push_back(i);
       }
    }
    
    
    // Topological sorting in the Graph
   
   // stack storing the topo sort from the dfs traversal 
    stack<int>stk;
    
    vector<bool>visited(V,false);
    
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,stk);
        }
    }
    
    vector<bool>visited2(V,false);
    
    // no of strongly connected componenets
    int cnt=0;
    
    while(!stk.empty())
    {
        int x= stk.top();
        stk.pop();
        
        if(!visited2[x])
        {
            dfs2(x,visited2,adj2);
            cnt++;
        }
    }
    
    return cnt;


}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
  // } Driver Code Ends