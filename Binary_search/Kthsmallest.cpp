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
int count(vector<int>a, int ele)
{
  int total=0;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]<=ele)
      total++;
  }
  return total;
}
int ksmall(vector<int>arr, int n, int k)
{
  int l= *min_element(arr.begin(),arr.end());
  int r= *max_element(arr.begin(),arr.end());
  int indx=0;
  while(l<=r)
  {
    int m=(l+r)/2;
    int cnt1=count(arr,m);
    if(cnt1<k)
    {
      l=m+1;
    }
    else
    {
      int cnt2= count(arr,m-1);
      if(cnt2<k)
      {
        indx=m;
        break;
      }
      else r=m-1;
    }
  }
  return indx;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
 int n,k;cin>>n>>k;
 vi v(n);
 for(int i=0;i<n;i++) cin>>v[i];
 cout<<ksmall(v,n,k)<<endl;
}
}
// T.C= nlog(max-min)
