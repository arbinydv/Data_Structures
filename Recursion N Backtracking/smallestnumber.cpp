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
#define lmaxx LLONG_MAX
#define lminn LLONG_MIN
#define modulo 1e9+7;
vi operated(vi &num,int n1, int n2, char op)
{
  vi nums;
  if(op=='*')
  {
    nums.pb(num[n1]*num[n2]);
  }
  else
  {
    nums.pb(num[n1]+num[n2]);
  }
  for(int i=0;i<num.size();i++)
    {
      if(i==n1 || i==n2) continue;
      nums.pb(num[i]);
    }
return nums;
}
void getmin(vi &num,vector<char>&operators,int index,int &cur_min)
{
  if(index==3)
  {
    cur_min= min(cur_min,num[0]);
    return;
  }
  //creating 2 childs
  for(int i=0;i<num.size();i++){
    for(int j=i+1;j<num.size();j++)
    {
      vi newnum= operated(num,i,j,operators[index]);
      getmin(newnum,operators,index+1,cur_min);
    }
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 vi num(4);
 vector<char>operators(3);
 for(int i=0;i<4;i++)
        cin>>num[i];
 for(int i=0;i<3;i++)
      cin>>operators[i];

 int cur_min=lmaxx;      //cur_min is the mimimum result we can get as answer at last
 getmin(num,operators,0,cur_min);
 cout<<cur_min;
}
