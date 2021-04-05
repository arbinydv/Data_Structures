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
//Agressive cow problem implementation of binary search technique
const int mx = 100005;
int n,c;
int stalls[mx];
int dist(int gap)   // current gap
{
  int countcows=1;
  int previous=0;   // the 1st cow is placed at the first position
  for(int i=1;i<n && countcows<c;i++)
  {
      if(stalls[i]-stalls[previous]>=gap)
      {
      countcows++; previous=i;  // for next cow prev=i;
      }
  }
  return countcows;
}
int binsearch(int low, int high)
{
  int ans=0;
  while(low<=high)
  {
    int mid= (low+high+1)/2;
    if(dist(mid)>=c)  // if we are able to fit all cows in gven gap then update asn and check for next higher gap
    {
      ans= mid;
      low= mid+1;
    }
    else
    {
      high=mid-1;
     }
  }
  return ans;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   cin>>n>>c;
   for(int i=0;i<n;i++)
   {
     cin>>stalls[i];
   }
   sort(stalls,stalls+n);
   int low=0, high= stalls[n-1];
   int distance= binsearch(low, high);
   cout<<distance<<endl;
 }

}
