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
// Subarrays with sum=k count using hashing technique
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 //what we will do is we will find out the no of Subarrays havin sum=k which ends at index i
 // for the we will store the prefixsum at each point and check for the prefsum-k in the map for its frequency
 // the frequency denotes how many time that pref-k has occured say x, which says there r x Subarrays with sum=k
 // Tc= 0(n)

  int n,k;
  cin>>n>>k;
  vi arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];

  int prefsum=0;
  int count=0;
  unordered_map<int,int> ump;
  ump.insert({0,1});   // inserting the Subarrays with 0 prefsum

  for(int i=0;i<n;i++)
  {
    prefsum+=arr[i];

    count+=ump[prefsum-k];   // how many indices we get the sum==k we will add their frequency
    ump[prefsum]++;
  }
  cout<<count;
}
