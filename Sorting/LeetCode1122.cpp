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
vi solve(vi &a1, vi &a2)
{
  vi freq(1001,0);
  for(int i=0;i<a1.size();i++)     // count of the element are stored at i number
  {
    freq[a1[i]]++;
  }
vi temp;
for(int j=0;j<a2.size();j++)
{
  for(int k=0;k<freq[a2[j]];k++)
    temp.pb(a2[j]);
  freq[a2[j]]=0;
}
for(int i=0;i<1001;i++)
{
  for(int j=0;j<freq[i];j++)    //rest of the elements are pushed back from arr1
    temp.pb(i);
}
return temp;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
vi a1={2,3,1,3,2,4,6,7,9,2,19};
vi a2= {2,1,4,3,9,6};
vi result= solve(a1,a2);
for(auto x:result)
cout<<x<<" ";
}
