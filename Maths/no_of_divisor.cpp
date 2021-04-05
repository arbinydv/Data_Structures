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
int  countfactors(int n)
{
  if(n<2) return 1;

  int first=SPF[n];  // store the smallest prime factor which divides the number
  int total_divisors=1;
  int j=n/SPF[n];  // will reduce to the number by first fctor to get other countfactors;
  int cnt=1;
  while(j!=1)   // to get the number of times a number is divided by next prime
  {
    if(SPF[j]==first)
     cnt++;
    else{
      first=SPF[j];   // we take next primes
      total_divisors=total_divisors*(cnt+1);
      cnt=1;
    }
    j/=SPF[j];
  }
  total_divisors= total_divisors*(cnt+1); // for last primes which is left;
  return total_divisors;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 sieve();
 int n;cin>>n;
 vi v(n);
 for(int i=0;i<n;i++) cin>>v[i];
  for(auto x:v)
  {
    cout<<countfactors(x)<<" ";
  }
// cout<<totalcount;
}
