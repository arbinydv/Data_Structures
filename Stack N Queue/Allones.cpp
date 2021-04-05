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
//Need All ones variation of max rectangle problems on HACKERRANK
int rectarea(vector<vector<int> > &arr)
{
  int temp= 0;
  int n=arr.size();
  if(n==0) return 0;
  int m=arr[0].size();
  if(m==0) return 0;

    vector<int>nse(m);
    stack<int>st;
    //column wise nse calculation
    st.push(0);
    for(int j=1;j<m;j++)
    {
      while(!st.empty() && (arr[n-1][st.top()]>arr[n-1][j]))
      {
        nse[st.top()]=j;
        st.pop();
      }
      st.push(j);
    }
    while(!st.empty())
    {
      nse[st.top()]= m;
      st.pop();
    }

    //column wise pse calculation
    vector<int> pse(m);
    stack<int>st1;
    st1.push(m-1);
    for(int j=m-2;j>=0;j--)
    {
      while(!st1.empty() && (arr[n-1][st1.top()]>arr[n-1][j]))
      {
        pse[st1.top()]=j;
        st1.pop();
      }
      st1.push(j);
    }
    while(!st1.empty())
    {
      pse[st1.top()]=-1;
      st1.pop();
    }
    for(int i=0;i<m;i++)
    {
      temp= max(temp,(nse[i]-pse[i]-1)*arr[n-1][i]);
    }
    return temp;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n,m;
 cin>>n>>m;
 vector<vector<int>> arr(n, vector<int>(m));
 for(int i=0;i<n;i++)
 {
   for(int j=0;j<m;j++)
   {
     cin>>arr[i][j];
   }
 }
 // creating the modified matrix
 for(int col=0;col<m;col++)
 {
   for(int row=1;row<n;row++)
   {
     if(arr[row][col]==0) continue;
     arr[row][col]+=arr[row-1][col];
   }
 }
 int ans= rectarea(arr);
 cout<<ans;

}
