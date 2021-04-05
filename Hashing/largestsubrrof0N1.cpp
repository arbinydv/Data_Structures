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
//largest subaarray with equal number of 0s and 1s using hashing concept
// we consider 0=-1 and 1=+1 and follow the approach of finding the longest subaarray length with equal 0s and 1s.
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
 int n;cin>>n;
 vi ar(n);
 for(int i=0;i<n;i++) cin>>ar[i];
 vi arr(n);
 for(int i=0;i<n;i++)
 {
   if(ar[i]==0)
   {
     arr[i]= -1;
   }
   else arr[i]=1;
 }

 vi pfsum(n);
 if(arr[0]==1)
 {
   pfsum[0]=1;
 }
 else pfsum[0]=-1;
 for(int i=1;i<n;i++)
 {
   pfsum[i]= pfsum[i-1]+arr[i];
 }
 for(auto it:pfsum) cout<<it<<" ";
 cout<<endl;
 ump mp;
 mp.insert({0,-1});
 int maxlength=0;

for(int i=0;i<n;i++)
{
  if(mp.find(pfsum[i])==mp.end())
  {
    mp[pfsum[i]]=i;
  }
  else
  {
    maxlength= max(maxlength,i-mp[pfsum[i]]);
  }
}
 cout<<maxlength<<"\n";
}
}
