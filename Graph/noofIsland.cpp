class Solution {
public:
    
    
    void DFS(int i, int j,int n,int m,vector<vector<char>>&grid)
    {
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1')
        {
            // mark  visited 
            grid[i][j]=0;
            
            DFS(i,j+1,n,m,grid);
            DFS(i,j-1,n,m,grid);
            DFS(i-1,j,n,m,grid);
            DFS(i+1,j,n,m,grid);
        }
        else
        {
            return ;
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        
        // at max there will be 4 max no of adjacent cells for the cell[i][j]
        if(grid.size()==0)
            return 0;
        
        int n= grid.size();
        int m=grid[0].size();
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    DFS(i,j,n,m,grid);
                    count++;
                }
            }
        }
        return count;
    }
};

//The modification of this problem will be when the adjacent diagonals too are considered as the adjacent 
// In this case we need to add 4 more cases becaause for the cell [i][j] it will have at max 8 adjacent cells which we need to check for the island
// The problem is actually broken down into finding out the number of connected components in the given graph
// TC: O(n2+ 16n2) when the n==vertices,e=edges when e=n then it will lead to n2 otherwise vn2+16e2)
