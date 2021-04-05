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
// hash map concpet using prefixsum
// subarray having sum==0 must be in the portion prefix[j]-prefixsum[i-1]
// so, PrefSum[j]-PrefSum[i-1]=0 --> prefSum[j]==pref[i-1]
//It implies from index i to J the subarray sum is zero.
// It's O(N) implementation and using unordered_map just to check if particulat prefsum key is present already

void solve()
{
  int n;
  cin>>n;
  vi arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  //storing the prefSum
  vi prefSum(n);
  prefSum[0]=arr[0];
  for(int i=1;i<n;i++)
  {
    prefSum[i]= prefSum[i-1]+arr[i];
  }

  // unordered_map for storing the sum and cheking if sum is repeated already
  ump mp;
  mp.insert({0,1});   // storing the empty subarray sum
  bool presence= false;   // to check subarray having sum=0;
  for(int i=0;i<n;i++)
  {
    if(mp.count(prefSum[i]))
    {
      presence=true;
      break;
    }
    // else insert into the map
    else mp[prefSum[i]]++;
  }
  if(presence) cout<<"Yes\n";
  else cout<<"NO\n";

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
