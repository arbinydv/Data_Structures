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
vector<vector<string>> ans;
bool isPalindrome(string &s1)
{
  string temp=s1;
  reverse(s1.begin(),s1.end());
  return temp==s1;
}
void palindrome(string &s,vector<string>&partition,int index)
{
  if(index==s.size())
  {
    ans.pb(partition);
    return;
  }
  //backtracking
  for(int j=index;j<s.size();j++)  //max partition size can be length of string
  {
    string temp;
    temp= s.substr(index,j-index+1);
    if(isPalindrome(temp))
    {
      partition.pb(temp);
      //check for the next part of the string
      palindrome(s,partition,j+1);
      partition.pop_back();
    }
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 string s;
 cin>>s;
 vector<string>partition;
 palindrome(s,partition,0);
 for(auto x:ans)
 {
   vector<string> vs= x;
   for(auto y:vs)
      cout<<y<<" ";
   cout<<endl;
 }
}
