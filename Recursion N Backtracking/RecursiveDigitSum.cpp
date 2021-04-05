//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long int
#define vi vector<int>
#define pp pair<int,int>
#define se set<int>
#define pb push_back
#define ump unordered_map<int,int>
#define maxx INT_MAX
#define minn INT_MIN
#define endl "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
int superDigit(string s, int k)
{
    // get the sum of the string first

    int supersum=0;
    for( char& c:s)
    {
        supersum+=c-48;
    }
    supersum*=k;
    // check if the sum is 1 digit or not

    if(supersum<10)
        return supersum;
    return superDigit(to_string(supersum),1);   // if the sum is not 1 digit then we will pass the sum to get further reduced and k=1 which won't affect any thing
    
}
int32_t main()
{
  string s; 
  int k;
  cin>>s>>k;
  cout<<superDigit(s,k);
}

