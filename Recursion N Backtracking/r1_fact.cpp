// find the factorial of a number using recursion
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fact(ll n)
{
  // base case where recursion stops
  if(n==0)
  {
    return 1;
  }
  ll res= fact(n-1)*n;
  return res;
}
int main()
{
  ll n;
  cin>>n;
  ll ans= fact(n);
  cout<<ans;
}
