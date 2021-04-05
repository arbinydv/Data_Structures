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

void dfs(int v,vector<bool>&visited,vector<int>adj[],stack<int>&stk)
{
    visited[v]= true;
    for(auto it:adj[v])
    {
        if(!visited[it])
            dfs(it,visited,adj,stk);
    }
    stk.push(v);
}

void dfs2(int x,vector<bool>&visited2,vector<int>trans[],int &cnt)
{
    visited2[x]=true;
    cnt++;

    for(auto neigh:trans[x])
    {
        if(!visited2[neigh])
        {
            dfs2(neigh,visited2,trans,cnt);
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

   // if a node leads to connected component then mark it as 1 else 0
    // run kajaraju's algorithms

    int n,m;
    cin>>n>>m;
    
    vector<int>adj[n+1];

    vector<int>trans[n+1];

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        trans[v].push_back(u);
    }

    vector<bool>visited(n+1,false);
    vector<bool>visited2(n+1,false);

    stack<int>stk;
    
    for(int i=1;i<n+1;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,stk);
        }
    }
    
    vector<int>result(n+1,1);
    while(!stk.empty())
    {
        int temp= stk.top();
        stk.pop();
        if(visited2[temp]==false)
        {
            int cnt=0;
            dfs2(temp,visited2,trans,cnt);

            // if count==1 then from this node we can be sure that there is no strongly connected component
            // if count>0 then we can be sure that the node is involved in a strongly connected component
            if(cnt==1)
                result[temp]=0;

        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<result[i]<<" ";
    }
 
    return 0;
}

