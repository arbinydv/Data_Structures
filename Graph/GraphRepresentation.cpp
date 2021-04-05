#include<bits/stdc++.h>
using namespace std;
// Simple Representation of Graph
//  0 <->  1
//            2
// 4  <->  3 

// A utility function to add Edge in undirected graph
void addEdge(vector<int>adj[],int u, int v)
{
    // since it's undirected so two way linkage u->v and v->u linkage
    adj[u].push_back(v);
    adj[v].push_back(u); 

}

//A utility function to print the adjacency list
void printGraph(vector<int> adj[], int V)
{
    for(int v=0;v<V;v++)
    {
    cout<<"\n Adjacency list of vertex "<<v<<" \n head";
    for(auto it:adj[v])
    {
       cout<<"->"<<it;
    }
    cout<<endl;
    }
}

int main()
{
    // no of vertices
    int V=5; 
   
   // adjacency list 
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,3,4);

    // Print the adjacency list associated with the vertices v
    printGraph(adj,V);

}