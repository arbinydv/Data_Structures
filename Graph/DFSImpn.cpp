/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
// Geeks for Geeks
// TC: 0(v+2*e) SC= O(v)
// DFS of graph is like DFS of the tree and the only catch we need to avoid is the repetition of node which can be avoided by using a bool arr
// which tells if the node is already visited or not.
void DFS(int v,bool visited[],vector<int>g[],vector<int>&adj)
{
    visited[v]=true;
    adj.push_back(v);
    
    for(auto e:g[v])
    {
        if(!visited[e])
        {
            DFS(e,visited,g,adj);
        }
    }
}
vector <int> dfs(vector<int> g[], int N)
{
    
    // Your code here
    bool visited[N];
    for(int i=0;i<N;i++)
    {
        visited[i]=false;
    }
    
    vector<int>adj;
    DFS(0,visited,g,adj);
    return adj;
    

}