
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
int findX(int i,vector<int>&par)
{
    while(par[i]!=i)
    {
        i=par[i];
    }
    return i;
    
}

bool unionset(int i, int j,vector<int>&par,vector<int>&sze)
{
    int ri= findX(i,par);
    int rj= findX(j,par);
    
    if(ri==rj) return false;   // lies in the same subset so cycle is formed
    
    int size_i= sze[ri];
    int size_j= sze[rj];
    
    if(size_i>size_j)
    {
        par[rj]= ri;
        sze[ri]+=sze[rj];
    }
    else
    {
        par[ri]=rj;
        sze[rj]+=sze[ri];
    }
    return true;
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   // Cycle detection using Disjoint Set Union method
   
   //creating parent and size vector 
   
   vector<int>par(V),sze(V);
   
   for(int i=0;i<V;i++)
   {
       par[i]=i;
       sze[i]=1;
   }
 
   set<pair<int,int>>st;
   
   for(int i=0;i<V;i++)
   {
       for(int j=0;j<g[i].size();j++)
       {
           int rj= g[i][j];
           
           //search if that exist in the set
           
           if(st.find({i,rj})!=st.end() || st.find({rj,i})!=st.end())   continue;
           if(!unionset(i,rj,par,sze)) return true;
           
           st.insert({i,rj});
           st.insert({rj,i});
       }
       
   }
   return false;
   
   
}
int32_t main()
{
    FAST           
    #ifndef ONLINE_JUDGE

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    // cycle detection in an undirected graph using Disjoint Set Union method
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
    return 0;
}

