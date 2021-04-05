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
#define modul 1e9+7
// Check whether the sub-string s2 is the permutation of the String S1 or not ( Important question)
// If the s2.size() character matches with the S1 in the given length of s2 then it is the permutation of s1
// USE of sliding window
// step 1: store the freq of s1 and s2 till the length of s2 in maps
// step2: compare the char if its matches then true
//step3 :if not matches then slide the s1 window by 1 and remove the preceeding char freq from the map
// T.C= 0(S-s1.size()) + SC= 2*0(26) for storing the characters
bool matches(int s1map[],int smap[]);
bool checkpermut(string s,string s1)
{
  if(s1.size()>s.size()) return false;
  //use of sliding window
  int smap[26]={0};
  int s1map[26]={0};
  for(int i=0;i<s1.size();i++)
  {
    int temp= s[i]-'a';
    int temp2= s1[i]-'a';
    smap[temp]++; s1map[temp2]++;
  }
  for(int i=0;i<s.size()-s1.size();i++)  // no need to go till s2 size
  {
    if(matches(s1map,smap))   // charcters stored are same or not
       return true;
    smap[s[i+s1.size()]-'a']++;
    smap[s[i]-'a']--;  // window's sucessor is removed for sliding window aaagadii
  }
  return matches(s1map,smap);
}
bool matches(int s1map[], int smap[])
{
  for(int i=0;i<26;i++)
  {
    if(s1map[i]!=smap[i])
    return false;
  }
  return true;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 string s1,s2;
 cin>>s1>>s2;
 bool result= checkpermut(s1,s2);
 cout<<result;

}
