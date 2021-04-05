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
void nextsmallest(vi &heights, int n,vi &NSE)
{
  stack<int>st;
  st.push(0);
  for(int i=1;i<n;i++)
  {
    while(!st.empty() && (heights[st.top()]>heights[i]))
    {
      NSE[st.top()]=i;
      st.pop();
    }
    st.push(i);
  }
  while(!st.empty())
  {
    NSE[st.top()]=n;
    st.pop();
  }
}
void prevsmallest(vi &heights, int n,vi &PSE)
{
  stack<int>st;
  st.push(n-1);
  //PSE[0]=-1; // first element does not have any smaller element before it

  for(int i=n-2;i>=0;i--)
  {
    while(!st.empty() && heights[st.top()]>heights[i])
    {
      PSE[st.top()]=i;
      st.pop();
    }
    st.push(i);
  }
  while(!st.empty())
  {
    PSE[st.top()]=-1;
    st.pop();
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 vi heights={2,1,5,6,2,3};
 int n=heights.size();
 vi  NSE(n),PSE(n); // Next Smaller element and Previous Smaller element of arr[i]-->heights
 nextsmallest(heights,n,NSE);
 prevsmallest(heights,n,PSE);
  // for(auto e:NSE) cout<<e<<" ";
  // cout<<endl;
 // for(auto it:PSE) cout<<it<<" ";
 int area=minn;
 for(int i=0;i<n;i++)
 {
   area = max((NSE[i]-PSE[i]-1)*heights[i],area);
 }
 cout<<area;
}
