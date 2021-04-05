#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/

void BFS(int x,vector<int>&ans,bool visited[],vector<int> g[])
{
    queue<int>q;
    
    visited[x]=true;
    q.push(x);
    
    while(!q.empty())
    {
        int x=q.front();
        ans.push_back(x);
        q.pop();
    for(auto y: g[x])
    {
        if(!visited[y])
        {
            visited[y]=true;
            q.push(y);
        }
    }
    }
    
}
vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    vector<int>ans;
    bool visited[N];
    
    for(int i=0;i<N;i++)
    {
        visited[i]=false;
    }
    
    BFS(0,ans,visited,g);
    
    return ans;
    
}