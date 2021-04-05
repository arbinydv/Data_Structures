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
   int k=3;
   for(int i=0;i<n;i++) cin>>v[i];
   //create buckets of remainder;
   int triplets=0;
   vi freq(k,0);
   for(int i=0;i<n;i++)
   {
     freq[v[i]%k]++;
   }
   //2 loops to check all those 3 cases and counting the number of viable triplets
   for(int i=0;i<k;i++)   // bucketers
   {
     for(int j=i;j<k;j++)
     {
       int rem=(k-(i+j)%k)%k;
       if(rem<j) continue;
       //case 1 if i==j==rem  all ares smae nc3
       if(i==j && rem==j)
       {
         triplets+=freq[i]*(freq[i]-1)*(freq[i]-2)/6;
       }
       // case 2 either 2 of them are equal nc2 cases
       else if(i==j)
          triplets+=freq[i]*(freq[i]-1)*freq[rem]/2;
       else if(i==rem)
          triplets+=freq[i]*(freq[i]-1)*freq[j]/2;
       else if(rem==j)
          triplets+=freq[j]*(freq[j]-1)*freq[i]/2;
       //case 3 if all are different nc1
       else
          triplets+=triplets+freq[i]*freq[j]*freq[rem];
     }
   }
   cout<<triplets;
 }
}
