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
void generatesubsets(vi &ar,int index,vi &subset, vi &temp)
{
  if(index==ar.size())
  {
    subset.pb(accumulate(temp.begin(),temp.end(),0));
    return;
  }
  //exclude
  generatesubsets(ar,index+1,subset,temp);
  //include
  temp.pb(ar[index]);
  generatesubsets(ar,index+1,subset,temp);
  temp.pop_back(); // to restore for the next
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   int n;
   cin>>n;
   vi ar(n);
   for(int i=0;i<n;i++) cin>>ar[i];
   vi subset;
   vi temp;
   generatesubsets(ar,0,subset,temp);
   for(auto x:subset)
   {
    cout<<x<<" ";
    }
     cout<<endl;
   }
}
