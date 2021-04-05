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
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 int arr[n];
 for(int i=0;i<n;i++) cin>>arr[i];
 vi dist;
 for(int i=0;i<n;i++)
 {
   if(arr[i]==1)
    dist.pb(i);
 }
 if(dist.size()==0)
 {
   cout<<0;
 }
 else
 {
 vi pref;
 for(int i=1;i<dist.size();i++)
 {
   pref.pb(dist[i]-dist[i-1]);
 }
 int ans=1;
 for(auto x:pref)
 {
   ans*=x;
 }
 cout<<ans;
}
}
