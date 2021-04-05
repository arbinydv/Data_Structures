//In Hardwork I trust
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
//global declaration of SPF for 1 time computation
const int mx=100004;
int SPF[mx]={0};
void sieve()
{
  SPF[1]=1;
  for(int i=2;i<mx;i++)
          SPF[i]=i;


  for(int i=2;i*i<=mx;i++)
  {
    if(SPF[i]==i)
    {
      for(int j=i*i;j<=mx;j+=i)
      {
        if(SPF[j]==j)
          SPF[j]=i;
      }
    }
  }
}
vi getfactors(int n)
{
  vi temp;
  while(n!=1)
  {
    temp.pb(SPF[n]);
    n/=SPF[n];
  }
  return temp;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 sieve();
 int q;cin>>q;
 while(q--)
 {
   int n;cin>>n;
   vector<int>ans= getfactors(n);
   for(auto ele:ans)
   {
     cout<<ele<<" ";
   }
   cout<<endl;
 }
}
