#include<bits/stdc++.h>
using namespace std;
#define int long long int
void sieve(int upper, vector<int>&prime)
{
  bool p[upper+1];
  memset(p,true,sizeof(p));
  for(int i=2;i<=upper;i++)
  {
    if(p[i])
    {
      for(int j=i*i;j<=upper;j+=i)
        {
          p[j]=false;
        }
      }
  }
  for(int i=2;i<=upper;i++)
  {
    if(p[i])
    prime.push_back(i);
  }
}
void getprimes(int l, int r, vector<int>&ans)
{
  int  lr = ceil(sqrt(r));
  vector<int>prime;
  sieve(lr,prime);
  int n=r-l+1;  // total element in the range
  bool checked[n+1];  // to cross out all the multiples of the prime number
  memset(checked,false,sizeof(checked));

  for(int i=0;i<prime.size();i++)
  {
    int spf= floor(l/prime[i])*prime[i]; // to get the first multiple of the prime in range
    if(spf<l) spf+=prime[i];
    if(spf==prime[i]) spf+=prime[i];  // next multples laii mark garna
    for(int j=spf;j<=r;j+=prime[i])
      checked[j-l]=true;
  }
  for(int i=l;i<=r;i++)
  {
    if(!checked[i-l])
      ans.push_back(i);
  }
}
int32_t main()
{
  int modu=1e9+7;
  int t;cin>>t;
  while(t--)
  {
    int l,r;
    cin>>l>>r;
    vector<int>ans;
    getprimes(l,r,ans);
    int total=1;
    for(auto x:ans)
    {
      total=(total*x)%modu;
    }
    cout<<total%modu<<endl;

  }
}
