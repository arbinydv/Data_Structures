//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long int
#define vi vector<int>
#define pp pair<int,int>
#define pb push_back
//codeforces B
// Learning: we have done the work in less than  n^2 compl
//stored the wasted land in set so that we can check it in logn if present
//set also helps to give the no of wasted lands before (a,b) using lowerbound and distance
// we will get all those cells (including wasted) using given formula
// reduce the value from no of wast from beginning till a,b;
// check the remiander and accordingly print the value

int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n,m,k,t;
 cin>>n>>m>>k>>t;
 set<pp>s;
  while(k--)
  {
    int x,y;
    cin>>x>>y;
    s.insert(make_pair(x,y));
  }
while(t--)
{
  int a,b;
  cin>>a>>b;
  if(s.count({a,b}))   // count returns 1 if the ele is present
  {
    cout<<"Waste\n";
  }
  else
  {
    int ans= (a-1)*m+(b-1);
    auto count= distance(s.begin(),s.lower_bound({a,b})); // distance is used to compute no of ele in the range
    ans-=count;
    ans%=3;
    switch (ans) {
      case 0: cout<<"Carrots\n"; break;
      case 1: cout<<"Kiwis\n"; break;
      case 2: cout<<"Grapes\n"; break;
      default :break;
    }
  }
}
}
