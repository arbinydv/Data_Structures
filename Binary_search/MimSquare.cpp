class Solution {
public:
    int minsumofsquare(int mid,vector<vector<int>>& mat,int threshold, int row, int col)
    {
      //perform range sum of the matrix operations
      for(int i=mid-1;i<row;i++)
       for(int j=mid-1;j<col;j++)
           int sum=mat[i][j];
           int i1= i-mid, j1= j-mid;
           if(i1>=0 && j1>=0) sum+=mat[i1][j1]-(mat[i][j1]+mat[i1][j]);
           else if (i1>=0) sum -=mat[i1][j];
           else if(j1>=0) sum-=mat[i][j1];

      return sum;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

      int row= mat.size();
      int col=mat[0].size();

      //prefix and suffix computation
      //inclusion and exclusion principle
      for(int i=0;i<row;i++)    // prefix sum along the row
      {
        for(int j=1;j<col;j++)
            mat[i][j]+=mat[i][j-1];
      }
      for(int i=0;i<col;i++)    // prefix sum along the column
      {
        for(int j=1;j<row;j++)
            mat[j][i]+=mat[j-1][i];
      }

      //Binary search for the threshold value
      int low=1, high= min(row,col);    // so that square can be formed
      int ans=0;
      while(low<=high)
      {
        int mid= low+(high-low)/2;
        int x= minsumofsquare(mid,mat,threshold,row,col);
        int y=minsumofsquare(mid+1,mat,threshold,row,col);
        if(x)
        {
          if(mid==0 || !y)
            return mid;
          low= mid+1;
        }
        else high=mid-1;
      }
      return ans;
    }
};
