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
bool isSafe(vector<vector<int>>&maze, int i, int j)
{
  return ((i>=0 && i<maze.size()) && (j>=0 && j<maze.size()) && maze[i][j]!=0);
}
void countPath(vector<vector<int>>&maze, int i, int j, bool &flag)
{
  //base case
  if(flag)
  {
    return;
  }
  if(i==maze.size()-1 && j==maze.size()-1)
  {
    flag=true;
    maze[i][j]=-1;
    for(int i=0;i<maze.size();i++)
    {
      for(int j=0;j<maze.size();j++)
      {
        if(maze[i][j]==-1)
        {
          cout<<1<<" ";
        }
        else
        {
          cout<<0<<" ";
        }
      }
      cout<<endl;
    }
    return;
  }
  int old_val= maze[i][j];   //stores the value at i,j so that we can know no of iterations
  maze[i][j]=-1;   //marking the current path as visited.
  for(int k=1;k<old_val+1;k++)
  {
    if(isSafe(maze,i,j+k))
    {
      countPath(maze,i,j+k,flag);     //move towards right
    }
    if(isSafe(maze,i+k,j))          //move down
    {
      countPath(maze,i+k,j,flag);
    }
  }
  maze[i][j]=old_val;    //undo
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;
 cin>>t;
 while(t--)
 {
   int n;cin>>n;
   vector<vector<int>> maze(n, vector<int>(n));
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<n;j++)
      cin>>maze[i][j];
   }
   maze[n-1][n-1]=1;    //last route is the destination which should be non zero
   bool flag= false;
   countPath(maze,0,0,flag);
   if(!flag)
   {
  //   cout<<"No Path Exist"<<endl;
     cout<<" -1"<<endl;
   }
 }
}
