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
//Remove Duplicate letters and print the lexicographically smallest substring
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 string s;cin>>s;
 int freq[26]={0};
 for(int i=0;i<s.size();i++)
 {
  freq[s[i]-'a']++;
 }
 vector<bool> present(26,false); // to check if char is present later or not in the string
 stack<char>stk;
 freq[s[0]-'a']--;
 stk.push(s[0]); // push the first character in the stack
 present[s[0]-'a']=true;
 for(int i=1;i<s.size();i++)
 {
   freq[s[i]-'a']--; //reduce the freq
   if(present[s[i]-'a'])
   {
     continue;     // the character is alredy present in the later part so ignore it
   }
   while(!stk.empty() && s[i]<stk.top() && freq[stk.top()-'a']>0)
   {
    present[stk.top()-'a']=false;
    stk.pop();
   }
   stk.push(s[i]);
   present[s[i]-'a']=true;
 }
 string ans="";
 while(!stk.empty())
 {
   ans+=stk.top();
   stk.pop();
 }
 reverse(ans.begin(),ans.end());
 cout<<ans;
}
