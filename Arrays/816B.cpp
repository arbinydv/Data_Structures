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

 //Intution : Use of Gold mars trickery to solve the problem
 // the range which falls: lower is ++ and higher is -- at higher+1 bcoz higher will reaches its destination
 int admissabletemp[200005]={0};
 int n,k,q;
 cin>>n>>k>>q;
 while(n--)   // all the rages are handle
 {
   int l,r;
   cin>>l>>r;
   admissabletemp[l]++;
   admissabletemp[r+1]--;
 }
 //compute prefix sum of the admissabletemp
 for(int i=1;i<200005;i++)
 {
   admissabletemp[i]=admissabletemp[i]+admissabletemp[i-1];
 }
 // marking 0 and 1 for the wherever k value is satisfied: k== true mark 1 else mark 0
for(int i=0;i<200005;i++)
{
  if(admissabletemp[i]>=k) admissabletemp[i]=1;
  else admissabletemp[i]=0;
}
//we have two choices either to iterate in q ranges or just get the job done using prefixsum so that we
// can havve the range values in o(1) time
//compute final prefixsum for the admissable recipie
for(int i=1;i<200005;i++)
{
  admissabletemp[i]=admissabletemp[i]+admissabletemp[i-1];
}
while(q--)
{
  int l,r;cin>>l>>r;
  cout<<admissabletemp[r]-admissabletemp[l-1]<<endl;
}


}
