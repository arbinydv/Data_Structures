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
void solve(vi &v, int n)
{
  int left=-1,right=-1;
  //finding the culprit chunk position from left and right
  for(int i=0;i<n-1;i++)
  {
    if(v[i]>v[i+1])
    {
      left= i;
      break;
    }
  }
  for(int j=n-1;j>=1;j--)
  {
    if(v[j]<v[j-1])
    {
      right= j;
      break;
    }
  }
  //find min and max in the chunk starting from i to j
  int a= *min_element(v.begin()+left,v.begin()+right+1);
  int b= *max_element(v.begin()+left,v.begin()+right+1);
  //cout<<a<<" "<<b;
 //finding the exact position of min and max element in the given array
 for(int i=0;i<n;i++)
 {
   if(a<v[i])
   {
     left=i;
     break;
   }
 }
 for(int i=n-1;i>=1;i--)
 {
   if(b>v[i])
   {
     right=i;
     break;
   }
 }
 cout<<left<<" "<<right;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;
 cin>>t;
 while(t--)
 {
   int n;
   cin>>n;
   vi v(n);

   for(int i=0;i<n;i++)
    cin>>v[i];
  solve(v,n);
  cout<<endl;
 }

}
