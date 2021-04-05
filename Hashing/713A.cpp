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
#define ump unordered_map<int,int>
#define maxx INT_MAX
#define minn INT_MIN
//Cf 713A
int bintodecimmal(string s)
{
  string temp;
  for(int i=0;i<s.size();i++)
  {
    if((s[i]-48)%2==0)
       temp+='0';
    else temp+='1';
  }
  //convert string 1100 into decimal
  int numb=0, j=1;
  for(int i=temp.size()-1;i>=0;i--)
  {
    if(temp[i]=='1')
      numb+=j;
    j*=2;
  }
  return numb;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 ump freq;
 while(t--)
 {
   char c; cin>>c;
   string n;
   if(c=='+'|| c=='-')
   {
     cin>>n;
     int temp= bintodecimmal(n);
     if(c=='+')
      freq[temp]++;
    else freq[temp]--;
   }
   else
   {
     string s; cin>>s;
     int temp2= bintodecimmal(s);
     cout<<freq[temp2]<<endl;
   }
 }

}
