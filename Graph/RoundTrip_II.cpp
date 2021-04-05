#include<bits/stdc++.h>
using namespace std;
// Checking if the directed graph is cyclic or not and then printing the cycle in it 
// white= unvisited, grey= visited but not finished, black= visited and finished 
// DFS and using color marking method wheere we keep track of node color
// Intially all node==0 white color unvisited, from each unvisited node start DFS and while entering
// for DFS make vertex as gray(1) and while exiting mark it as black=2. 
// in this way while itration if a vertex is already marked gray=it means there is a cycle
vector<char>color;
vector<int>parent;
int cycle_begin,cycle_end;

// dfs
bool dfs(int v, vector<int>adj[])
{
    color[v]=1;   // visited color=1;
    
    for(auto it:adj[v])
    {
        if(color[it]==0)
        {
            parent[it]=v;  // store the node val in parent array
            if(dfs(it,adj))
             return true;
        }
        else if(color[it]==1)   // node already visited but under exploration so cycle is formed
        {
            cycle_begin=it;
            cycle_end=v;
            return true;
        }
    }
    color[v]=2; // visited and finished exploring 
    return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    color.assign(n,0);  // all white 
    parent.assign(n,-1); 

    // check if there exist a cycle or not
    cycle_begin=-1;
   bool present=false;
    for(int i=0;i<n;i++)
    {
        if(color[i]==0 && dfs(i,adj))   // cycle is found 
        {
            present=true;
            break;
        }
            
    }
    if(!present)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        vector<int>cycle;
        //cout<<cycle_begin;
        cycle.push_back(cycle_begin);
        for(int i=cycle_end;i!=cycle_begin;i=parent[i])
            cycle.push_back(i);
        cycle.push_back(cycle_begin); // starting and ending at same node
        
        // reverse to get the first node where the cycle started or using stack to store the element
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<endl;
        for(auto c:cycle)
            cout<<c<<" ";
    }
    


   
}