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
const int N= 1e5+5;
int amount[N];
int supplies[N];
int n,k;
int max(int a,int b)
{
  if(a>b) return a;
  else return b;
}
bool countCookies(int x)
{
  int count=0;
  for(int i=0;i<n;i++)
  {
    if((amount[i]*x)>supplies[i] && (amount[i]*x-supplies[i])>0)
    {
      count+= amount[i]*x-supplies[i];
    }
      if(count>k) return false;
  }
    return true;
}
int binsearch(int low, int high)
{
  while(low<high)
  {
    int mid= (low+high+1)/2;
    bool x= countCookies(mid);
    if(x)
    {
      low=mid;
    }
    else
    {
      high=mid-1;
    }
  }
  return max(0,low);
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 cin>>n>>k;
 for(int i=0;i<n;i++) cin>>amount[i];
 for(int i=0;i<n;i++) cin>>supplies[i];
 int low=0,high=2e9+5;
 int ans= binsearch(low, high);
 cout<<ans;
}
