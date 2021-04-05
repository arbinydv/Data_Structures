#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool DFS(int vertex,vector<bool>&visited,vector<bool>&curr,vector<int> adj[])
{
    // if current vertex is not visited earlier then it's safe to visit
    if(curr[vertex]==false)
    {
        curr[vertex]=true;   // backtracking purpose
        visited[vertex]=true;   
        
        for(auto neighbor:adj[vertex])
        {
            if(!visited[neighbor] && DFS(neighbor,visited,curr,adj))
                return true;
            if(curr[neighbor])
                return true;
        }
        curr[vertex]=false;  // backtracking
        return  false;
    }
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    
    // for all nodes
    vector<bool>visited(V,false);
    
    // for the current vertex
    vector<bool>curr(V,false);
    
    for(int v=0;v<V;v++)
    {
        if(DFS(v,visited,curr,adj))
            return true;
    }
    return false;
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends