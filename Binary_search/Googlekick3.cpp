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
const int N=1e5+7;

//Google kickstart 2020 Problem 3: workout
int n,k;
vi arr(N);
bool sessions(int d)
{
  //d is the difficulty level
  int total_sessions=0;
  for(int i=1;i+1<=n;i++)
  {
    total_sessions+=(arr[i+1]-arr[i]-1)/d;
  }
  if(total_sessions<=k) return 1;
  else return 0;
}
int binsearch(int low, int high)
{
  while(low<high)
  {
    int mid= (low+high)/2;
    if(sessions(mid))
    {
        high=mid;
    }
    else low=mid+1;
  }
  return low;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 int tc=0;
 while(t--)
 {
   tc++;
   cin>>n>>k;
  // vi arr(n+1);
   for(int i=1;i<n+1;i++) cin>>arr[i];
   int diff= binsearch(1,1e10);
   cout<<"Case #"<<tc<<": "<<diff<<endl;

 }


}
