//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
using namespace std;
#define int long long int

// Solution 1 where we store the cell co-ordinates only as a pair in the queue
int ShortestPath(int a,int b, int x,int y,vector<vector<int>>&mat)
{
    // a,b=source  x,y= destination
    // path cannot be reachable 
    if(mat[0][0]==0 || mat[x][y]==0)
    {
        return -1;
    }
    // source and destination is same then return 0

    if(a==x && b==y)
    {
        return 0;
    }
    // visited matrix
    vector<vector<bool>>visited(mat.size(),vector<bool>(mat[0].size(),false));
    queue<pair<int,int>>q;

    // shortest distance
    int distance=0;
    visited[a][b]=true;
    q.push({a,b});

    // 4 direction BSF call
    vector<int>rowrange={-1,0,1,0};
    vector<int>colrange={0,1,0,-1};

    // BFS
    while(!q.empty())
    {
        int sz=q.size();

        while(sz--)
        {
            pair<int,int> temp = q.front();
            int xx= temp.first;
            int yy= temp.second;
            q.pop();

           // BFS calls
           for(int i=0;i<4;i++)
           {
               int u= xx+rowrange[i];
               int v= yy+colrange[i];
            
                // safe
               if(u>=0 && u<mat.size() && v>=0 && v<mat[0].size())
               {
                   // if the cell is reached 
                   if(u==x && v==y)
                   {
                       distance++;
                       return distance;
                   }
                   if(!visited[u][v] && mat[u][v]==1)
                   {
                       // mark visited
                       visited[u][v]=true;
                       q.push({u,v});
                   }

               }
           }

        }
        distance++;
    }
    return -1;
}

//Solution 2 where we store pair of < distance, {i,j} > in the queue

bool isSafe(int i, int j,int m, int n)
{
    return (i>=0 && i<m && j>=0 && j<n);
}
int BFS(int a,int b,int x, int y, vector<vector<int>>&mat)
{
    if(mat[0][0]==0 || mat[x][y]==0)
    {
        return -1;
    }

    if(a==x && b==y)
    {
        return 0;
    }

    vector<vector<bool>>visited(mat.size(),vector<bool>(mat[0].size(),false));

    queue<pair<int,pair<int,int>>>q;
    visited[a][b]=true;
    q.push({0,{a,b}});

    int m=mat.size();
    int n=mat[0].size();

    while(!q.empty())
    {
        pair<int,pair<int,int>> p = q.front();
        q.pop();

        int i=p.second.first;
        int j=p.second.second;

        if(i==x && j==y)
        {
            return p.first;
        }

        // call for 4 BFS
        if(isSafe(i-1,j,m,n) && mat[i-1][j]==1)
        {
            q.push({p.first+1,{i-1,j}});
            
            // mark visited
            visited[i-1][j]=true;

        }
        if(isSafe(i+1,j,m,n) && mat[i+1][j]==1)
        {
            q.push({p.first+1,{i+1,j}});
            
            // mark visited
            visited[i+1][j]=true;

        }
        if(isSafe(i,j-1,m,n) && mat[i][j-1]==1)
        {
            q.push({p.first+1,{i,j-1}});
            
            // mark visited
            visited[i][j-1]=true;

        }
        if(isSafe(i,j+1,m,n) && mat[i][j+1]==1)
        {
            q.push({p.first+1,{i,j+1}});
            
            // mark visited
            visited[i][j+1]=true;

        }
    }
    return -1;
      
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
     int m,n;
     cin>>m>>n;
     vector<vector<int>>mat(m,vector<int>(n,0));
     for(int i=0;i<m;i++)
     {
         for(int j=0;j<n;j++)
            cin>>mat[i][j];
     }
     int x,y;
     cin>>x>>y;
    
    // Calling Utilitity function 1st for the shortest Path
    // int ans= ShortestPath(0,0,x,y,mat);
    
    // Calling Utility function 2nd for the shortest Path
     
     int ans= BFS(0,0,x,y,mat);
    
     if(ans==-1)
     {
         cout<<"-1";
     }
     else
     {
         cout<<ans;
     }
     cout<<endl;
 }
 
return 0;
}