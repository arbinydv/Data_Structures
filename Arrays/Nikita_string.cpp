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
//#define max INT_MAX
#define min INT_MIN
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 string s;
 cin>>s;
 // creating the prefix of a count and b count

 // the string is beautiful if it has aaaaa   bbbb   aaaa form
 // or aba
 // so we divide them in 3 part and remove b from i till N in first part, a in second part, and b in third part
 //  aaba  bbab   aaba --> aa(remove b)a   bb (remove a)b  aa(remove b) a --> makes string beautiful
 // thus we taken prefix of a[i to N], prefix_b[i+1 to N];
 // // total len= pref[i]+pref_b[j]- pref_b[i] + pref_a[N-1]- pref[a];
 // which is pref[i till i+1](a,b), pref[i+1 till j](a,b), pref[j till N](a,b);
 vi pref_a,pref_b;
 pref_a.pb(0);
 pref_b.pb(0);
 for(char c:s)
 {
   if(c=='a')
   {
     pref_a.pb(pref_a.back()+1);
     pref_b.pb(pref_b.back());
   }
   else
   {
     pref_b.pb(pref_b.back()+1);
     pref_a.pb(pref_a.back());
   }
 }
 int maxleng=0;
 for(int i=0;i<pref_a.size();i++)
 {
   for(int j=i;j<pref_a.size();j++)
   {
     int templen=pref_a[i]+pref_b[j]-pref_b[i]+pref_a[s.size()]-pref_a[j];
     maxleng=max(maxleng,templen);

   }
 }
 cout<<maxleng;
}
