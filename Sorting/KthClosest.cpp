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
bool static comp(pp &a,pp &b)
{
  int da= (a.first*a.first)+(a.second*a.second);
  int db= (b.first*b.first)+(b.second*b.second);
  return da<db;
}
vector<vector<int>>kClosest(vector<vector<int>>& points, int K) {
  vector<pair<int,int>>v(points.size());
  for(int i=0;i<points.size();i++)
  {
    v[i].first=points[i][0];
    v[i].second=points[i][1];
  }
  sort(v.begin(),v.end(),comp);
  vector<vector<int>>ans;
  for(int i=0;i<K;i++)
  {
    vector<int>temp;
    temp.push_back(v[i].first);
    temp.push_back(v[i].second);
  }
  return ans;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 vector<vi>points={{-5,4},{-6,-5},{4,6}};
 int k=2;
 vector<vector<int>> ans= kClosest(points,k);
}
