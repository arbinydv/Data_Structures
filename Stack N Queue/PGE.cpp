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
//Previous Greater Element in stack
//Previous Smaller Element in stack Implementation
void PGE(vi &ar, int n)
{
  stack<int>st;
  st.push(0);
  //for first element the previous element will always be -1
  vi pge(n);
  pge[0]=-1;
  for(int i=1;i<n;i++)
  {
    while(!st.empty() && (ar[st.top()]<ar[i]))   // pop if stack top is less than currne tlement
    {
      st.pop();
    }
    if(st.empty())
      pge[i]=-1;
    else pge[i]= ar[st.top()];
    st.push(i);
  }
  for(auto it:pge) cout<<it<<" ";
}
void PSE(vi &ar, int n)
{
  stack<int>st;
  st.push(0);
  vi pse(n);
  pse[0]=-1; // first element does not have any smaller element before it
  for(int i=1;i<n;i++)
  {
    while(!st.empty() && ar[st.top()]>ar[i])
    {
      st.pop();
    }
    if(st.empty())
      pse[i]=-1;
    else pse[i]=ar[st.top()];
    st.push(i);
  }
  for(auto it:pse) cout<<it<<" ";
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 vi ar(n);
 for(int i=0;i<n;i++) cin>>ar[i];
 PGE(ar,n);
 cout<<endl;
 PSE(ar,n);
}
