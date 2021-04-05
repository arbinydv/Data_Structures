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
// Stack Implementation of Next smaller element in O(n) time complexity
void NSE(vi &v, int n)
{
  stack<int>st;
  int nse[n];
  st.push(0);
  for(int i=1;i<n;i++)
  {
    while(!st.empty() && (v[st.top()]>v[i]))
    {
      nse[st.top()]=v[i];
      st.pop();
    }
    st.push(i);
  }
  while(!st.empty())
  {
    nse[st.top()]=-1;
    st.pop();
  }
  for(auto it:nse)
    cout<<it<<" ";

}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 vi v(n);
 for(int i=0;i<n;i++) cin>>v[i];
 NSE(v,n);

}
