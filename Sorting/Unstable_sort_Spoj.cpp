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
#define endl "\n"
bool comp(pair<int,int>&a, pair<int,int>&b)
{
  if(a.first!=b.first)
  {
    return a.first<b.first;      // if element are different then simply return a<b
  }
  return a.second>b.second;      // if ele are same then  simply return b>a for unstability
}
void unstablesort(int a[],int n)
{
  //store the element and index of each element
  vpp arr;
  for(int i=1;i<=n;i++)
  {
    arr.pb({a[i],i});
  }
  sort(arr.begin(),arr.end(),comp);
  for(auto it:arr)
  {
    cout<<it.second<<" ";
  }

}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 int a[n+1];
 for(int i=1;i<n+1;i++)
  cin>>a[i];
 unstablesort(a,n);
}
