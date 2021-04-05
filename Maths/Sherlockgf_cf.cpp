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
int sieve[100005];
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 for(int i=2;i<=n+1;i++)
 {
   if(!sieve[i])
   {
     for(int j=2*i;j<=n+1;j+=i)
     {
       sieve[j]=1;
     }
   }
 }
int ans=1;
if(n>2)
{
  ans=2;
}
cout<<ans<<endl;
for(int i=2;i<=n+1;i++)
{
  if(!sieve[i])
  {
    cout<<1<<" ";
  }
  else cout<<2<<" ";
}
return 0;
}
