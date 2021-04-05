//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long int
#define vi vector<int>
#define pp pair<int,int>
#define vpp vector<pair<int,int> >
#define se set<int>
#define pb push_back
#define mp map<int,int>
#define maxx INT_MAX
#define minn INT_MIN
#define modulo 1e9+7;
#define endl "\n"
vector<vector<char>>res;
bool isSafe(int i, int j, vector<vi>&maze)
{
  int n=maze.size();
  if((i>=0 && i<=n-1) &&(j>=0 && j<=n-1) && maze[i][j]==1)
    return true;
  else return false;
}
void computePath(vector<vi>&maze,int i,int j, vector<char>&path)
{
  int n=maze.size();
  // left right up down L R U D
  if(i==n-1 && j==n-1)    // at the destionation
  {
    // for(char c:path)
    //   cout<<c;
    // cout<<" ";
    res.pb(path);
    return;
  }
  if(maze[i][j]==0)     // 0--> blocked path and 1--> Valid path
    return;

  //Backtracking
   maze[i][j]=0;
  //left for (i,j)
  if(isSafe(i,j-1,maze) && (maze[i][j-1]==1))
  {
    path.pb('L');
    computePath(maze,i,j-1,path);
    path.pop_back();
  }
  // right movement
  if(isSafe(i,j+1,maze) && (maze[i][j+1]==1))
  {
    path.pb('R');
    computePath(maze,i,j+1,path);
    path.pop_back();
  }
  //up movement from i,j
  if(isSafe(i-1,j,maze) && (maze[i-1][j]==1))
  {
    path.pb('U');
    computePath(maze,i-1,j,path);
    path.pop_back();
  }
  //down movement from i,j
  if(isSafe(i+1,j,maze) && (maze[i+1][j]==1))
  {
    path.pb('D');
    computePath(maze,i+1,j,path);
    path.pop_back();
  }
  maze[i][j]=1;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   int n;cin>>n;
   vector<vi>maze(n,vi(n));
   for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>maze[i][j];
   vector<char>path;
   computePath(maze,0,0,path);
   sort(res.begin(),res.end());
   for(auto x:res)
      {
        vector<char> ans=x;
        for(auto c:ans)
          cout<<c;
        cout<<" ";
      }
   cout<<endl;
  res.clear();
 }
}
