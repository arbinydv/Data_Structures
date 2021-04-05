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
//Leetcode Ship capacity Problem Prob: 1011
bool isPossible(int weights[], int n, int d, int mid)
{
  int daycount=1;
  int cargo=0;
  for(int i=0;i<n && daycount<=d;i++)
  {
    if(cargo+weights[i]>mid)
    {
      cargo=weights[i];
      daycount++;
      if(daycount>d) return false;
    }
    else
    {
      cargo+=weights[i];
    }
  }
  return true;
}
int findpage(int weights[], int n, int d)
{
  int low=0;
  int high= 0;
  int temp=0;
  for(int i=0;i<n;i++)
  {
    temp+=weights[i];
    low=max(low,weights[i]);
  }
  high=temp;
  int leastweight=low;
  while(low<=high)
  {
    int mid= (low+high)/2;
    if(isPossible(weights, n,d,mid))
    {// exist then check for smaller values of mid in the left bound so that we can get the min values of book allocation
      leastweight= mid;
      high=mid-1;
    }
    else
    {
      low= mid+1;
    }
  }
  return leastweight;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   int n,d;
   cin>>n>>d;
   int weights[n];
   for(int i=0;i<n;i++) cin>>weights[i];
   cout<<findpage(weights, n,d)<<endl;
 }
}
