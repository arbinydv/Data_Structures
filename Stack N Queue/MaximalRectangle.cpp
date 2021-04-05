class Solution {
public:
      int maxRectangle(vector<vector<int>>&ar)
      {
        int n=ar.size();
        int m= ar[0].size();
        int temp=0;
        for(int i=0;i<n;i++)    //row wise calculation of the rectangle
        {
          vector<int> nse(m);
          stack<int>st;
          st.push(0);
          for(int j=1;j<m;j++)
          {
            while(!st.empty() && (ar[i][st.top()]> ar[i][j]))
            {
              nse[st.top()]=j;
              st.pop();
            }
            st.push(j);
          }
          while(!st.empty())
          {
            nse[st.top()]=m;
            st.pop();
          }
             //finding previous smaller element
          vector<int> pse(m);
          stack<int> st1;
          st1.push(m-1);
          for(int j=m-2;j>=0;j--)
          {
            while(!st1.empty() && (ar[i][st1.top()]>ar[i][j]))
            {
              pse[st1.top()]= j;
              st1.pop();
            }
            st1.push(j);
          }
          while(!st1.empty())
          {
            pse[st1.top()]= -1;
            st1.pop();
          }
       int maxrect=INT_MIN;
       for(int j=0;j<m;j++)
        {
          maxrect= max(maxrect,(nse[j]-pse[j]-1)*ar[i][j]);
        }
         temp= max(maxrect,temp);
       }
       return temp;
      }
    int maximalRectangle(vector<vector<char>>& matrix) {
      int n=matrix.size();
      int m= matrix[0].size();
      if(n==0) return 0;
      if(m==0) return 0;
      vector<vector<int>> ar(n,vector<int>(m));
      //converting into integer
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
           ar[i][j]= matrix[i][j]-'0';

      for(int i=0;i<m;i++)
      {
        for(int j=1;j<n;j++)
        {
            if(ar[j][i]==1)
            {
              ar[j][i]+=ar[j-1][i];
            }
        }
      }
      int ans= maxRectangle(ar);
      return ans;
    }
};
