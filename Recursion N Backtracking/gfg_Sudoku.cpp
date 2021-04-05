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
//Sudoku implementation using backtracking
#define N 9
bool leftover(int board[N][N],int &row,int &col);
bool isSafe(int board[N][N],int row,int col, int num);
bool solveSudoku(int board[N][N])
{
  int r,c;
  if(!leftover(board,r,c))
    return true;    //all cells are assigned with some values

  for(int n=1;n<=9;n++)
  {
    if(isSafe(board,r,c,n))
    {
      //backtracking
      board[r][c]=n;
      if(solveSudoku(board))
        return true;

      board[r][c]=0;

  }
}
return false;
}
bool leftover(int board[N][N],int &row,int &col)   // check for any vacant cells inside the sudoku arena
{
  for(row=0;row<N;row++)
   for(col=0;col<N;col++)
      if(board[row][col]==0)
          return true;
  return false;
}
bool inrow(int board[N][N], int row, int num)
{
  //if number is already present in row then return true else false
  for(int col=0;col<N;col++)
    if(board[row][col]==num)
      return true;
  return false;

}
bool incol(int board[N][N], int col, int num)
{
  //if number is already present in col then return true else false
  for(int r=0;r<N;r++)
    if(board[r][col]==num)
      return true;
  return false;
}
bool alreadyinMatrix(int board[N][N],int i,int j, int num)    // if the matrix grid already contains the number then we cannot assingn it
{
  for(int r=0;r<3;r++)
  {
    for(int col=0;col<3;col++)
      if(board[i+r][j+col]==num)
        return true;
  }
  return false;
}
//check if a cell can be assigned with a number or not while making comparison with row,col, and inside the matrix grid
bool isSafe(int board[N][N],int row,int col, int num)
{
  return !inrow(board,row,num) && !incol(board,col,num) && !alreadyinMatrix(board,row-row%3,col-col%3,num) && board[row][col]==0;
}
void print(int board[N][N])
{
  for(int r=0;r<N;r++)
   {
     for(int c=0;c<N;c++)
     cout<<board[r][c]<<" ";
     cout<<endl;
   }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 #ifndef ONLINE_JUDGE
  
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif

 int board[N][N]={{0,0,0,6,0,8,0,0,0},
                  {0,0,3,0,0,0,7,0,0},
                  {9,8,0,0,0,0,0,3,6},
                  {0,1,0,7,0,3,0,9,0},
                  {0,0,5,9,0,1,8,0,0},
                  {0,0,6,2,0,4,5,0,0},
                  {0,2,9,0,0,0,3,7,0},
                  {6,0,0,0,0,0,0,0,8},
                  {0,7,8,0,2,0,1,6,0}
                };

  if(solveSudoku(board)==true)
  {
    print(board);
  }
  else
  {
    cout<<"No solution exist!";
  }
return 0;
}
