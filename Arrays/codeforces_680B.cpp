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
 int n,a;
 cin>>n>>a;
 vi v(n);
 for(int i=0;i<n;i++)
 {
   cin>>v[i];
 }
 a--;
 int i=a-1;
 int j=a+1;
 int crim=v[a];
 while(i>=0 && j<n)
 {
   if(v[i]==1 && v[j]==1)
   {
     crim+=2;
   }
   i--;
   j++;
 }
 while(i>=0)
 {
   if(v[i]==1) crim++;
   i--;
 }
 while(j<n)
 {
   if(v[j]==1) crim++;
   j++;
 }
 cout<<crim;
}
