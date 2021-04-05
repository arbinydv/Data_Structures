class Solution {
public:
     void dfs(vector<vector<char>>& board, int i, int j)
     {
         if(i>=0 && i<board.size() && j>=0 && j<board[0].size() && board[i][j]=='O')
         {
             // make visited as V
             board[i][j]='V';

             // call 4 cell dfs 
             dfs(board,i-1,j);
             dfs(board,i+1,j);
             dfs(board,i,j-1);
             dfs(board,i,j+1);
         }
         else return;
     }
    void solve(vector<vector<char>>& board) {
        
        // ignore the boundary 0 
        
        int row = board.size();
        if(row==0)
            return;
        
        int col=board[0].size();
        
        // first row
        for(int i=0;i<col;i++)
        {
            if(board[0][i]=='O')
            {
                // run dfs in it's neighbouring cells
                dfs(board,0,i);
            }
            // last row
            if(board[row-1][i]=='O')
            {
                dfs(board,row-1,i);
            }
        }
        
        // checking the column boundary
        
        for(int j=0;j<row;j++)
        {
            // first column
            if(board[j][0]=='O')
            {
                dfs(board,j,0);
            }
            // last column
            if(board[j][col-1]=='O')
            {
                dfs(board,j,col-1);
            }
        }
        
        // checking for the cells inside the boundaries
        // if 0 then we will simply change the state from o to x
        
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                // check the case before replacement
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                if(board[i][j]=='V')   // boundary 0
                {
                    board[i][j]='O';
                }
                
            }
        }   
        
    }
};