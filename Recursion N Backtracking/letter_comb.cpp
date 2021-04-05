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
void lettercomb(vector<string>vs,string digits, vector<string>&ans, int indx, string curr)
{
  if(curr.size()==digits.size())
  {
    ans.pb(curr);
    return;
  }
  int numb= digits[indx]-'0';
  string letter= vs[numb];
  for(int i=0;i<letter.size();i++)
  {
    lettercomb(vs,digits,ans,indx+1,curr+letter[i]);
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 vector<string>vs{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
 string digits;
 cin>>digits;
 vector<string>ans;
 string curr="";
 lettercomb(vs,digits,ans,0,curr);
 for(auto x:ans)
 {
   cout<<x<<" ";
 }


}
