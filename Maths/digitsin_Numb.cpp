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
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 //number of 1 in a digits
 int n;cin>>n;
 int ans=0;
 int chunk=1;
 while(chunk<=n)
 {
   ans+=(n/(10*chunk))*chunk;
   //to deal with the last number we need to extract 2 MSB of the number thus
   // to generate 1st term
   int first=(n/(10*chunk))*(10*chunk)+chunk;
   //we need to get the value till which we have to go which can be extracted
   // simply by taking the n-first if n>first

   if(n>=first)
      ans+=min(chunk,n-first+1);
   chunk*=10;
 }
 cout<<ans;

}
