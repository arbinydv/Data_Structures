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
const int N=1e5 + 7;
int n,s;
int soven[N];
int actualcost[N];
int maxsov(int mid)
{
  for(int i=0;i<n;i++)
  {
    actualcost[i]= soven[i]+ mid*(i+1);
  }
  sort(actualcost,actualcost+n);
  int sum=0;
  for(int i=0;i<mid;i++)
  {
    sum+=actualcost[i];
  }
  return sum;
}
vector<int> binsearch(int low, int high)   // passing array as pointer
{
  vi ans;
  while(low<high-1)
  {
    int mid= low+(high-low)/2;
    int x= maxsov(mid);
     if(x <=s)
     {
       low=mid;
     }
  else
  {
    high=mid;
  }
  }
  ans.pb(low);
  ans.pb(maxsov(low));
  return ans;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 cin>>n>>s;
 for(int i=0;i<n;i++) cin>>soven[i];
 vi ans=binsearch(0,n+1);
 cout<<ans[0]<<" "<<ans[1];
}
