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
stack<int>st;
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 int cur_max= minn;
 while(n--)
 {
     int a;cin>>a;
     if(a==1)
     {
         int x; cin>>x;
         if(st.empty())
         {
           st.push(x);
           cur_max=x;
         }
         else if(x>cur_max)
         {
           int temp= x+cur_max;   // store the max values which can be retrieved back
           st.push(temp);
           cur_max=x;
         }
         else st.push(x);
     }
     else if(a==2)
     {
         if(st.top()>cur_max)
         {
           cur_max=st.top()-cur_max;
         }
           st.pop();
     }
     else
     {
         cout<<cur_max<<endl;
     }
 }

}
