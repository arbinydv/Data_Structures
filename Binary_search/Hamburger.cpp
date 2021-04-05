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
#define mp map<char,int>
#define maxx INT_MAX
#define minn INT_MIN
#define modulo 1e9+7;
string s;
int nb,ns,nc,pb,ps,pc,budget;
int bread,sauc,chees;
int recipie[3];
bool countofhamb(int mid)
{
  int sum=0;
  if(mid*bread>nb) sum+=(mid*bread-nb)*pb;
  if(mid*sauc>ns) sum+=(mid*sauc-ns)*ps;
  if(mid*chees>nc) sum+=(mid*chees-nc)*pc;
  return sum<=budget;
}
int binsearch(int low, int high)
{
  while(low<high)
  {
    int mid= (high+low+1)/2;
    bool x=countofhamb(mid);
    if(x)
    {
      low=mid;
    }
    else
    {
      high=mid-1;
    }
  }
  return low;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 string s;
 cin>>s;
 //stored the count of breads, sausage and cheese
 for(int i=0;i<s.size();i++)
 {
   if(s[i]=='B') bread++;
   if(s[i]=='S') sauc++;
   if(s[i]=='C') chees++;
 }
 cin>>nb>>ns>>nc>>pb>>ps>>pc;
 cin>>budget;
 int ans= binsearch(0,1e13);
 cout<<ans;
}
