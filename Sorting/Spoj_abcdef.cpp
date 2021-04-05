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
int sixlets(vector<int>&set, int n)
{
  // a*b+ c= d(e+f);
  //use of vector to store the lhs perms
  vi a1,a2;
  //a*b+c ko laagi
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){    // single ele can be assigned multiple roles
      for(int k=0;k<n;k++)
      {
         int lhs= set[i]*set[j]+set[k];
         a1.pb(lhs);
       }
     }
   }
  //for second part d(e+f)
  for(int p=0;p<n;p++){
    for(int q=0;q<n;q++){
      for(int r=0;r<n;r++){
         if(set[p]==0)  continue;
         int rhs= set[p]*(set[q]+set[r]);
         a2.pb(rhs);
      }
    }
  }
  sort(a2.begin(),a2.end());
 // find the occurence of ele in a1 in a2
 //use of binary search
 int total=0;
 for(auto x:a1)
 {
   auto it=lower_bound(a2.begin(),a2.end(),x);
   auto it2= upper_bound(a2.begin(),a2.end(),x);
   total+=(it2-it);
 }
return total;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;
 cin>>n;
 vi set(n);
 for(int i=0;i<n;i++)
    cin>>set[i];
  cout<<sixlets(set,n);
}
