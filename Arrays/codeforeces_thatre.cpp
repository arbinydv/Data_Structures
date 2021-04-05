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
 // pascal triangle is created so that we can get the value of ncr at row icj and thus overflow will be handled
 int u=62;
 int pascal[u][u]={0,0};
 for(int i=0;i<u;i++)
 {
   for(int j=0;j<=i;j++)
   {
     if(i==j|| j==0)
     {
       pascal[i][j]=1;
     }
     else
     {
       pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
     }
   }
 }
int n,m,t;
cin>>n>>m>>t;
int ans=pascal[n+m][t];
ans=ans-pascal[n][t];
for(int i=3;i>=0;i--)
{
  ans= ans-pascal[n][i]*pascal[m][t-i];
}
cout<<ans;

}
