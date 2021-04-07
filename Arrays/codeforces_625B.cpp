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
// To count the no of occurence of substring t in the given string s
void counts(string s,string t)
{
  if(s.size()<t.size())
 {cout<<0;
   return;
 }
   auto pos= s.find(t);  // will find where string t starts  first occurence
   vi res;
   while(pos!=string::npos)
   {
     // vector res will store the size of substring starting at t[0]
     res.pb(pos);

     // pos will be shifted to the next occurence of the t[0] substring in  the String s from  t_size()
     pos= s.find(t,pos+t.size());
   }
   cout<<res.size();

}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 string s,t;
 cin>>s>>t;
 counts(s,t);
}
