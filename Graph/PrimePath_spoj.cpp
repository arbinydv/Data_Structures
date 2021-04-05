#include<bits/stdc++.h>
using namespace std;
void seive(int n, vector<int>&primes,int low)
{
    bool p[n+1];
    memset(p,true,sizeof(p));

    for(int i=2;i<=sqrt(n);i++)
    {
        if(p[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                p[j]=false;
            }
        }
    }

    for(int i=low;i<=n;i++)
    {
        if(p[i])
          primes.push_back(i);
    }
}

// Utility function to check if two nodes are connected
// Two nodes are connected if they differ by a single digit
bool isConnected(int a,int b)
{
    string s1,s2;
    s1= to_string(a);
    s2=to_string(b);

    int cnt=0;
    for(int i=0;i<4;i++)
    {
        if(s1[i]!=s2[i])
            cnt++;
    }
    if(cnt==1)
        return true;
    return false;
}
int main()
{
    vector<int>primes;
    seive(10000,primes,1000);

    // creating adjacency list of the primes which are connected
    vector<int> adj[primes.size()];

    for(int i=0;i<primes.size();i++)
    {
        for(int j=i+1;j<primes.size();j++)
        {
            if(isConnected(primes[i],primes[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int t; cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        // find the index in primes for the source and destination
        int i=lower_bound(primes.begin(),primes.end(),n)-primes.begin();
        int j= lower_bound(primes.begin(),primes.end(),m)-primes.begin();

        // BFS calls
        
        // queue will contain the source and the distance 
        queue<pair<int,int>>q; 
        q.push({i,0});
        // visited matrix
        vector<bool>visited(primes.size(),false);
        visited[i]=true;

        int hops= -1;
        while(!q.empty())
        {
            pair<int,int> p= q.front();
            q.pop();
            // check if the source reached destination
            if(p.first==j)
            {
                hops=p.second;
                break;
            }
        // esle make BFS calls for the adjacency list of the node
         for(auto it:adj[p.first])
         {
             // checked visited
             if(!visited[it])
             {
                q.push({it,p.second+1});
                visited[it]=true;
             }
         }
        }

        cout<<hops<<endl;

    }
}