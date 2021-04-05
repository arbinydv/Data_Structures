class Solution {
public:
    bool solSudoku(vector<vector<char>>& board)
    {
      int r,c;
      if(!leftover(board,r,c))   // means all cells are occupied with some values
      {
        return true;
      }

      for(int n=1;n<=9;n++)   // check if a  number can be assigned
      {
        if(isSafe(board,r,c,n))
        {
          board[r][c]=char(n+'0');
          if(solSudoku(board))
          {
            return true;
          }
          board[r][c]='.';
        }
      }
      return false;
    }
    bool leftover(vector<vector<char>>& board,int &row, int &col)
    {
      for(row=0;row<9;row++)
        for(col=0;col<9;col++)
          if(board[row][col]=='.')
            return true;
      return false;
    }
    bool checkrow(vector<vector<char>>& board,int row,int num)
    {
      for(int col=0;col<9;col++)
      {
        if(board[row][col]==char(num+'0'))
          return true;
      }
      return false;
    }
    bool checkcol(vector<vector<char>>& board,int col,int num)
    {
      for(int row=0;row<9;row++)
      {
        if(board[row][col]==char(num+'0'))
          return true;
      }
      return false;

    }
    bool checkinmatrixgrid(vector<vector<char>>& board,int i,int j, int num)
    {
      for(int r=0;r<3;r++)
      {
        for(int col=0;col<3;col++)
          if(board[i+r][j+col]==char(num+'0'))
            return true;
      }
      return false;
    }
    bool isSafe(vector<vector<char>>& board,int row,int col, int num)
    {
      return !checkrow(board,row,num) && !checkcol(board,col,num) && !checkinmatrixgrid(board,row-row%3,col-col%3,num) && board[row][col]=='.';
    }
    void print(vector<vector<char>>& board)
    {
      for(int r=0;r<9;r++)
       {
         for(int c=0;c<9;c++)
         cout<<board[r][c]<<" ";
         cout<<endl;
       }
    }
    void solveSudoku(vector<vector<char>>& board) {
      if(solSudoku(board))
      {
        print(board);
      }
    }
};
