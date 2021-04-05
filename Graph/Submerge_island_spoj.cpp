//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pb push_back
#define maxx INT_MAX
#define minn INT_MIN
#define N 10005
#define endl "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

// Problem to find the articulation point  in the connected undirected graph 
// SPOj Submerge Island

vector<int>adj[N];
vector<int>discovery_time(N);
vector<int>lowest_time(N);
int time_spent;
vector<int>visited(N);
set<int>AP;  // articulation point 
void dfs(int i, int par)
{
    visited[i]=1;
    time_spent++;
    discovery_time[i]=time_spent;
    lowest_time[i]= time_spent;

    int children=0; 

    for(int child:adj[i])
    {
        if(visited[child]==0)
        {
            dfs(child,i);
            children++;

            if(lowest_time[child]==discovery_time[i] && par !=-1)
            {
                AP.insert(i);  // the node is articulation point
            }
                
            lowest_time[i]= min(lowest_time[i],lowest_time[child]);
        }
        else 
        {
            lowest_time[i]= min(lowest_time[i],discovery_time[child]);
        }

        // checking for root node

        if(par==-1 && children>1)
        {
            AP.insert(i);
        }

    }
}
int32_t main()
{
    FAST           
    #ifndef ONLINE_JUDGE

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m,u,v;
    while (1)
    {
       cin>>n>>m;

       if(n==0 || m==0)
       break;

    // clearing the adjacency list
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        visited[i]=0;
    }
    
    //clearing the set
    AP.clear();

    time_spent=1;
    for(int i=1;i<=m;i++)
    {
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i,-1); // passing parent as -1
        }
    }
    
    cout<<AP.size()<<endl;
    }

    return 0;
}

