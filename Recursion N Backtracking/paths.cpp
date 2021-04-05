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
void totalways(int i,int j, int row, int col)
{
  if(i==row && j==col)
  {
    counter++;
    return;
  }
  if(i==row)  // we will recurse J
  {
     totalways(i,j+1,row,col);
  }
  else if(j==col)
  {
    totalways(i+1,j,row,col);
  }
  else
  {
    totalways(i+1,j,row,col);
    totalways(i,j+1,row,col);
  }

}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   int row,col;
   cin>>row>>col;
   totalways(0,0,row-1,col-1);
   cout<<counter<<endl;
   counter=0;
 }

}
