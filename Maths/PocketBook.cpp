//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long int
#define vi vector<int>
#define pp pair<int,int>
#define vpp vector<pair<int,int> >
#define se set<char>
#define pb push_back
#define mp map<int,int>
#define maxx INT_MAX
#define minn INT_MIN
//T.C=> O(n*m)*O(mlogn)
//S.C= O(n*m)+0(n)
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n,m;
 cin>>n>>m;
 const int modulo=1e9+7;
 char arr[n][m];
 for(int i=0;i<n;i++)
 {
   string s;
   cin>>s;
   for(int j=0;j<m;j++)
        arr[i][j]=s[j];
 }
 vi dist;

 for(int i=0;i<m;i++)
 {
    se unique;
   for(int j=0;j<n;j++)
   {
     unique.insert(arr[j][i]);
   }
   dist.pb(unique.size());
 }
 int ans=1;
 for(auto x:dist)
 {
   ans= (ans*x)%modulo;
 }
 cout<<ans%modulo;
}
