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
#define ump unordered_map<int,int>
#define maxx INT_MAX
#define minn INT_MIN
//implementation of longest subarray with sum=0 using the hasmap concept
void solve()
{
  int n;cin>>n;
  vi arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vi prefSum(n);
  prefSum[0]=arr[0];
  for(int i=1;i<n;i++)
  {
    prefSum[i]= prefSum[i-1]+arr[i];
  }
  ump mp;
  mp.insert({0,-1}); // for the initial empty subarray
  int maxlength=0;

  for(int i=0;i<n;i++)
  {
    if(mp.find(prefSum[i])==mp.end())
    {
      mp.insert({prefSum[i],i});   // the sum is not repeated yet so we store the value and index of first occurence
    }
    else
    {
      maxlength= max(maxlength,i-mp[prefSum[i]]);   //else we will calc the length of subarray for current occurence to first occurence of the prefSum
    }
  }
  cout<<maxlength;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   solve();
 }
}
