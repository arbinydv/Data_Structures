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

//Binary exponentiation using recursion
int power(int n,int k)
{
  if(k==0) return 1;
  else if(k%2==0)
  {
    int x= power(n,k/2);
    return x*x;
  }
  else   // for power is odd
  {
    int y= power(n,k/2);
    return y*y*n;
  }
}
// normal iteration is faster than the recursion
int normpwr(int n,int k)
{
  int res=1;
  while(k>0)
  {
    if(k%2==1)
    {
      res*=n;
    }
    n*=n;   // it is jumping like 2^n,2^n*2,2^n*2*2....power haru ma jump garidaii xa
    k/=2;
  }
  return res;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n,k;
 cin>>n>>k;
 int ans1= power(n,k);
 cout<<ans1<<endl;
 cout<<normpwr(n,k);
}
