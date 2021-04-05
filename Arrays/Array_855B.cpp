#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
  int n,p,q,r;
  cin>>n>>p>>q>>r;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  int prefMax[n],sufMax[n];
  //prefMax
  prefMax[0]=p*arr[0];
  for(int i=1;i<n;i++)
  {
    prefMax[i]= (prefMax[i-1]>p*arr[i]) ? prefMax[i-1]:p*arr[i];
  }
  //sufMax
  sufMax[n-1]=r*arr[n-1];
  for(int j=(n-2);j>=0;j--)
  {
    sufMax[j]= (sufMax[j+1]>r*arr[j]) ? sufMax[j+1]: r*arr[j];
  }

  int ans=INT_MIN;
  for(int k=0;k<n;k++)   // for cond i==j==k or others
  {
    int res= prefMax[k]+q*arr[k]+sufMax[k];
     ans= (ans>res) ? ans:res;
  }
  cout<<ans;

}
