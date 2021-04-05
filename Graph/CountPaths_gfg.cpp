#include<bits/stdc++.h>
using namespace std;

// To explore a path from source to destination in a directed graph, DFS can be used which
// while we're exploring all paths so the paths will be: no of directed nodes from source( adj list of a node)
// while iterating there might be a node which is common in midway of a different path and if we had marked it as visited earlier it will delimit the
// other path to reach the destination thus every time we need to mark it as false for other paths once we iterate through it therefore we need to use Backtracking in the DFS
//                A     C
//              B       D
//                      E
// source : A Dest: E there are 3 paths from A to E and node D shares a common point in path ACDE and ADE thus while traversing if we had marked D as visted then the path
// ADE would not have been explored which is not correct thus to avoid this once we iterate ACDE we mark D unvisited again

void count_paths(vector<int>Adj[], int source, int dest,vector<bool>visited,int&cnt)
{
    if(source==dest)
    {
        cnt++;
        return;
    }
    // backtracking for path from each nodes directly connected with the source 
    for(auto v:Adj[source])
    {
        if(!visited[v])
        {
        visited[v]=true;  
        count_paths(Adj,v,dest,visited,cnt);
        visited[v]=false;
        }
    }
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
       
       // Adjacency list for each vertices
        vector<int>Adj[V];  
        while(E--)
        {
            int u,v;
            cin>>u>>v;
            // graph is directed so vertex u is connected with v. 
            // we push each nodes of u which are directly connected with it and they are the possible outlets for different paths from a node to destination
            Adj[u].push_back(v);
        }
        // s=source , d= destination vertex
        int s,d;
        cin>>s>>d;
        vector<bool>visited(V,false); 

        visited[s]= true;   // source is marked
        int cnt=0;
        count_paths(Adj,s,d,visited,cnt);   // DFS

        cout<<cnt<<endl;

    }
}