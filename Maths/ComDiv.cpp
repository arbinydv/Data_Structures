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
 int t; cin>>t;
 while(t--)
 {
   int a,b,k,cnt=0;
   cin>>a>>b;
   int res= __gcd(a,b);
   if(res==1) cout<<1<<endl;
   else
   {
   for(int k=1;k<sqrt(res);k++)
   {
     if(res%k==0)
     {
       cnt+=2;
     }
   }
    if((k*k)==res)cnt+=1;
   }
   cout<<cnt<<endl;
 }

}
