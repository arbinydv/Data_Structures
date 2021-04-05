#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int upper=10000002;
vector<int>pref(upper,1);
void sieve(int n)
{
  pref[0]=0;
  pref[1]=0;
  for(int i=2;i<sqrt(upper);i++)
  {
    if(pref[i]==1)
    {
      for(int j=i*i;j<upper;j+=i)
      {
        pref[j]=0;
      }
    }
  }
  for(int i=1;i<upper;i++)
  {
     pref[i]+=pref[i-1];
  }
}
int32_t main()
{
  sieve(upper);
  int t;
  scanf("%lli\n",&t);
  while(t--)
  {
    int n;cin>>n;
    int ans= pref[n]-pref[n/2];
    printf("%lli\n",ans);
  }
}
