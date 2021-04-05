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
vector<int> sieve(int n)
{
  bool prime[n+1];
  memset(prime,true,sizeof(prime));
  for(int i=2;i*i<=n;i++)
  {
    if(prime[i])
    {
      for(int j=i*i;j<=n;j+=i)
      {
        prime[j]=false;
      }
    }
  }
  vi temp;
  for(int i=2;i<=n;i++)
  {
    if(prime[i])
      temp.pb(i);
  }
  return temp;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 vi v= sieve(1000005);
 int t;cin>>t;
 while(t--)
 {
   int n;cin>>n;
   int k=sqrt(n);
   auto it=binary_search(v.begin(),v.end(),k);
   if(it)
   {
     if(k*k==n)
        cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
   }
   else cout<<"NO"<<endl;
 }
}


//ANother Approoach
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 vector<bool> prime(ma+1,true);
  prime[0]==false;
  prime[1]=false;
   for(int i=2;i*i<=ma;i++)
   {
     if(prime[i]==1)
     {
       for(int j=i*i;j<=ma;j+=i)
       {
         prime[j]=false;
       }
     }
   }
  map<int,bool> res;
  for(int i=2;i<ma;i++)
  {
    if(prime[i])
    {
      res[i*i]=true;
    }
  }
 int t;cin>>t;
 vi temp(t);
 while(t--)
 {
   int n; cin>>n;
   if(res[n]) cout<<"YES\n";
   else cout<<"NO\n";

 }
}
