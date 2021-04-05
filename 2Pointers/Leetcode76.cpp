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
string minimumstring(string s, string t)
{
  if(s.size()<t.size())
    return "";
  //  cout<<"window cannot be formed";
  vi freqT(1000,0);
  int distinctchar=0;
  for(int i=0;i<t.size();i++)
  {
    if(freqT[t[i]]==0)
      distinctchar++;
    freqT[t[i]]++;
  }

  vi freqS(1000,0);
  int count=0;
  int i;
  for(i=0;i<s.size();i++)    // for instantaneous windows length and frequency
  {
    freqS[s[i]]++;
    if(freqS[s[i]]==freqT[s[i]])
      count++;
    if(count==distinctchar)
      break;
  }
  int start=0, end= i;
//  cout<<start<<" "<<end;   //first smallest substring with all chars in T
   //adobec odebanc
  //Two pointer concept to cut of useless chars
  int a=-1, b=-1;
  int minlength= maxx;
  while(end<s.size())
  {
    while(1)
    {
      if(freqT[s[start]]==0)
      {
        freqS[s[start]]--;
        start++;
      }
      else if(freqT[s[start]]==freqS[s[start]])
      {
        break;
      }
      else
      {
        freqS[s[start]]--;
        start++;
      }
    }
    if((end-start+1)<minlength)
    {
      a=start;
      b=end;
      minlength= end-start+1;
//      cout<< a<<" "<<b<<endl;
  //    cout<<minlength<<endl;
    }
    end++;
    if(end==s.size())
     break;
    freqS[s[end]]++;
  }
 if(a>b || (a==-1 && b==-1))
    return "";
//  cout<<"No window is present";
//  cout<<s.substr(a,b+1);
string ans="";
for(int k=a;k<=b;k++)
  ans+=s[k];

return ans;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
 string s,t;
 cin>>s>>t;
 cout<<minimumstring(s,t);
 cout<<endl;
}
}
