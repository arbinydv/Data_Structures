#include<bits/stdc++.h>
using namespace std;
void dfs(int v, vector<bool>&visited,unordered_set<int>adj[],string &s)
{
    visited[v]=true;

    for(auto it:adj[v])
    {
        if(!visited[it])
        {
            visited[it]=true;
            dfs(it,visited,adj,s);
        }
    }
    s.insert(s.begin(),'a'+char(v));
}
string findorder(vector<string>&dict,int N,int k)
{
    unordered_set<int>adj[k];
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++)
        {
            if(dict[i][j]!=dict[i+1][j])
            {
                // make the connection of index

                adj[dict[i][j]-'a'].insert(dict[i+1][j]-'a');
                break;
            }
        }
    }

    // topological_sorting 
    vector<bool>visited(k,false);

    string s;
    for(int i=0;i<k;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,s);
        }
    }
    return s;

}
int main()
{
    int t; cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<string>dict;
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            dict.push_back(temp);
        }

        string  ans= findorder(dict,n,k);
        cout<<ans<<endl;

    }
    
}