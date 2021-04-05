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
void longestdistinctsubstring(string &s)
{
  vector<int>pos(256,-1);
  int start=0,end=0;
  int ans=1;
  pos[s[0]]=0;
  int j=1;
  while(j<s.size())
  {
    if(pos[s[j]]==-1)
    {
      pos[s[j]]=j;
      end++;
    }
    else
    {
      int k=pos[s[j]];
      int i;
      for(i=start;i<=k;i++)
          pos[s[i]]=-1;
      start=i;
      end++;
      pos[s[end]]=end;
    }
    ans= max(ans,end-start+1);
    j++;

  }
  cout<<ans;

}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
string s;
cin>>s;
longestdistinctsubstring(s);
}
