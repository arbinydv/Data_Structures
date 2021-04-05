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
#define modulo 1e9+7;
int  maxdiff(vector<int> &weight, int n, int k)
{
  int ans=0;
  if(k<=(n/2))
  {
    // k no of smallest element
    int s1=0,s2=0;
    for(int i=0;i<k;i++)
       s1+=weight[i];
    s2= accumulate(weight.begin(),weight.end(),0)-s1;
    ans= abs(s1-s2);
  }
  else
  {
    int s1=0,s2=0;
    int totalsum= accumulate(weight.begin(),weight.end(),0);
    int res=n-k;
    for(int i=0;i<res;i++)
      s2+=weight[i];
    s1= totalsum-s2;
    ans= abs(s1-s2);
  }
  return ans;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   int k,n;
   cin>>n>>k;
   vi weight(n);
   for(int i=0;i<n;i++)
        cin>>weight[i];
  sort(weight.begin(),weight.end());
  cout<<maxdiff(weight,n,k);
  cout<<endl;
 }
}
