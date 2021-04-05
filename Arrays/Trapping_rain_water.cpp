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
// #define max INT_MAX
//#define min INT_MIN
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 vi v={0,1,0,2,1,0,1,3,2,1,2,1};
 int n=v.size();
 vi prefixMax(n);
 vi sufixMax(n);
 prefixMax[0]=v[0];
 for(int i=1;i<n;i++)
 {
   prefixMax[i]= max(prefixMax[i-1],v[i]);
 }
 for(auto x:prefixMax)
 {
   cout<<x<<" ";
 }
 cout<<endl;
 sufixMax[n-1]=v[n-1];
 for(int j=n-2;j>=0;j--)
 {
   sufixMax[j]= max(sufixMax[j+1],v[j]);
 }
 for(auto y:sufixMax)
 {
   cout<<y<<" ";
 }
 int trap_water=0;
 for(int i=1;i<n-1;i++)
 {
   int height= min(prefixMax[i-1],sufixMax[i+1]);
   if(v[i]<=height) trap_water+=(height-v[i]);
 }
 cout<<endl;
 cout<<trap_water;



}
