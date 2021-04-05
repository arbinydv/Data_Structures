#include<bits/stdc++.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
#define int long long int
#define vi vector<int>
#define pp pair<int,int>
#define form for(int i=0;i<n;i++)
#define se set<int>
#define pb push_back
#define mp map<int,int>
#define max INT_MAX
#define min INT_MIN
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n,m;
 cin>>n>>m;
 vi arr(n+1);
 for(int i=1;i<n+1;i++)
 {
   cin>>arr[i];
 }
 vi prefixsum(n+1);
 prefixsum[1]=arr[1];
 for(int i=2;i<n+1;i++)
 {
   prefixsum[i]= arr[i]+prefixsum[i-1];
 }
 int totalsum=0;
 while(m--)
 {
   int l,r;
   cin>>l>>r;
   int temp= prefixsum[r]-prefixsum[l-1];
   if(temp>=0) totalsum+=temp;

 }
 cout<<totalsum;

}
