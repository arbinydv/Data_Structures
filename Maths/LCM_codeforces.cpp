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
void lcm(int n)
{
  if(n<=2)
  {
    cout<<n;
    return;
  }
  if(n&1)
  {
    cout<<n*(n-1)*(n-2);
  }
  else if(n%3==0)
  {
    cout<<(n-1)*(n-2)*(n-3);
  }
  else cout<<max((n-1)*(n-2)*(n-3),n*(n-1)*(n-3));
 }
int32_t main()
{
 int mufasa= 1e9+7;
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 lcm(n);
}
