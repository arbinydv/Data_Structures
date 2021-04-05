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
int recursive_catalan(int n)
{
  if(n<=1) return 1;
  int ans=0;
  for(int i=0;i<n;i++)
  {
    ans+=recursive_catalan(i)*recursive_catalan(n-i-1);
  }
  return ans;
}

int dp_catalan(int n)
{
  //array to store the previously calculated catalan number
  int arr[n+1];
  arr[0]=arr[1]=1;
  for(int i=2;i<=n;i++)
  {
    arr[i]=0;
    for(int j=0;j<i;j++)
    {
      arr[i]+=arr[j]*arr[i-j-1];
    }
  }
  return arr[n];
}
int binomial(int n, int k)
{
  int res=1;
  //calculate nck=== c(n,n-k);
  if(n-k<k)
      k=n-k;

  //calculate the permutation and combination
  for(int i=0;i<k;i++)
  {
    res*=(n-i); // upper permutation
    res/=(i+1); //lower permutation
  }
  return res;

}
int bn_catalan(int n)
{
  int c= binomial(2*n,n);
  return c/(n+1);
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 //catalna number operation
 //3 solutions 1: recursion T.C=(2^n)
 // solution 2: dynamic programming T.C (n^2)
 // solution 3: Binomial coefficient : T.c(o(n))

// catalan number is symmetric and the nth catalan number is given by
// c(n)= c[0]*[n-1]+c[1]*[n-2]+.............c[i]*c[n-i-1]+c[n-1]*c[n]

//recursion

int n ; cin>>n;
cout<<recursive_catalan(n)<<endl;
cout<<dp_catalan(n)<<endl;
cout<<bn_catalan(n);


}
