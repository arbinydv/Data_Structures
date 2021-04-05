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
vi a;
int n,x;
bool possiblesum(int m)
{
  if(m==0) return true;
  int sum=0;
  for(int i=0;i<m;i++)
  {
    sum+=a[i];
    if(sum>x)
      return false;
  }
  int st=0,end=m;   // starting and ending point in legal area of size k
  while(end<n)     // implementation of sliding window over here such that we are cmputing all sums till n
  {
    sum -=a[st];
    st++;
    sum +=a[end];
    end++;
    if(sum>x)
    return false;
  }
  return true;
}
int binsearch(int low, int high)
{
  int ans=0;
  int mid;
  while(low<=high)
  {
    mid= (low+high)/2;
    bool sm= possiblesum(mid);
    if(!sm)
    {
      high=mid-1;
    }
    else
    {
      bool sm2=possiblesum(mid+1);
      if(!sm2)
      {
        ans=mid;
        break;
      }
      else
      {
        low=mid+1;
      }
    }
  }
  if(ans!=0) return ans;
  else return mid;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 cin>>n>>x;
 for(int i=0;i<n;i++)
 {
   int temp;cin>>temp;
   a.pb(temp);
 }
 int ans= binsearch(1,n);
 cout<<ans;
}
