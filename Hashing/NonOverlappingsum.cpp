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
//Finding if there exist two pairs whose sum is equal and those pairs differs by indices where i!=j!=m!=n.
//eg 8 4 7 6 4 8  --> (8,4) and (4,8) are possible and valid answer
//eg: 8 4 7 4 --> (4,7) and (7,4) cannot be the pairs as 7's indices overlapp or is same and thus it has no such pairs
// USE of hashmap to store the sum and indices of all possible pairs O(n2) for finding out all the pairs + 0(N) to store <sum,<pairs>>
void solve()
{
  int n;cin>>n;
  vi ar(n);
  for(int i=0;i<n;i++) cin>>ar[i];
  unordered_map<int,pp> mp;

  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      int sum= ar[i]+ar[j];

      //search if the sum already in map if yes then check the indices
      if(mp.find(sum)!=mp.end())
      {
        auto it= mp.find(sum);
        auto m= it->second.first;
        auto n= it->second.second;
         if((m!=i && m!=j) && (n!=i && n!=j))
          {
            cout<<ar[i] <<" "<<ar[j]<<endl;
            cout<<ar[m]<<" "<<ar[n]<<endl;
            return;
          }
      }
      // if not found then simply append them in map where each indices will
      // get stored in pairs of same sum.
      mp[sum]={i,j};
    }

  }
  cout<<"No such pairs exist in the given array";
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   solve();
 }

}
