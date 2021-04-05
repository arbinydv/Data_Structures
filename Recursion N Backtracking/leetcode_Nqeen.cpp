class Solution {
public:
  bool isSafe(vector<string>&board,int row, int col, int n)
  {
    //3 conditions r there
    //checking for the column
    for(int c=0;c<row;c++)
    {
      if(board[c][col]=='Q')
        return false;
    }
    // checking left diagonal
    int start= row,end=col;
    while(start>=0 && end>=0)
    {
      if(board[start][end]=='Q')
        return  false;
      start--;
      end--;
    }
    //checking for right diagonal
    int st=row, ed= col;
    while(st>=0 && ed<n)
    {
      if(board[st][ed]=='Q')
         return false;
      st--;
      ed++;
    }

    return true;
  }
  void placeNQueens(vector<vector<string> >&ans,vector<string> &board,int curr_row,int &n)
  {
    if(curr_row==n)
    {
      res.push_back(board);
      return;
    }
    //backtracking
    for(int column=0;column<n;column++)
    {
      if(isSafe(board,cur_row,column,n))
      {
        board[cur_row][column]='Q';
        placeNQueens(ans,board,cur_row+1,n);
        board[cur_row][column]='.';
      }
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string> > ans;
    vector<string> board(n, string (n, '.'));
    placeNQueens(ans,board,0,n);
    }
};
