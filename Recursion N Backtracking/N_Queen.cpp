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
bool isSafe(int board[][10], int i, int j, int n)
{
  //check 3 conditions
  //checking for the columns
  for(int r=0;r<i;r++)
    if(board[r][j]==1)
      return false;
  //checking for the left diagonal
 int st=i, end=j;
 while(st>=0 && end>=0)
 {
   if(board[st][end]==1)
   {
     return false;
   }
   st--;
   end--;
 }
 //checking for right diagonal
 int start=i;
 int e=j;
 while(start>=0 && e<n)
 {
   if(board[start][e]==1)
    return false;
   start--;
   e++;
 }

 return true;
}
bool placeQueen(int board[][10], int i, int n)
{
  if(i==n)
  {
    //print board
    for(int r=0;r<n;r++)
     {for(int c=0;c<n;c++)

       if(board[r][c]==1)
        cout<<"Q";
       else cout<<"_";
       cout<<endl;
     }
     cout<<endl;
  }
  for(int j=0;j<n;j++)   // we are checking in each column from 0 till n in row i
  {
    if(isSafe(board,i,j,n))
    {
      board[i][j]=1;
      bool nextqeen= placeQueen(board, i+1,n);
      if(nextqeen)
      {
        return true;
      }
      board[i][j]=0;
    }
  }
  return false;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 int board[10][10]={0};
 placeQueen(board,0,n);
}
