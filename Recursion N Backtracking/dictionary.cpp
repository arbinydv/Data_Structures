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
int counter=0;
void dictionary(string s)
{
  //base condition
  if(s.size()>3 || counter>15)
  {
    return;
  }
  if(s!="")
  {
  cout<<s<<endl;
  counter++;
  }
  dictionary(s+'a');
  dictionary(s+'b');
  dictionary(s+'c');

}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 string s="";
dictionary(s);

}
