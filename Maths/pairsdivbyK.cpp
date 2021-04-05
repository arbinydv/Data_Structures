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
 int t;cin>>t;
 while(t--)
 {
   int n;cin>>n;
   vi v(n);
   int k=4;
   for(int i=0;i<n;i++) cin>>v[i];
   //create buckets of remainder
   vi bkt(k,0);
   for(int i=0;i<n;i++)
   {
     bkt[v[i]%k]++;
   }
   int pairs= bkt[0]*(bkt[0]-1)/2;  // if the pairs are same eg: 4,4
   for(int i=1;i<=k/2 && i!=(k-i);i++)
   {
     pairs+=bkt[i]*bkt[k-i];
   }
   if(k%2==0)
    pairs+=(bkt[k/2]*(bkt[k/2]-1)/2);
    cout<<pairs<<endl;
 }
}
