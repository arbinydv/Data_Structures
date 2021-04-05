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
//Reversing Queue using stack
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 queue<int>q;
 stack<int>st;
 int n;cin>>n;
 while(n--)
 {
   int x;cin>>x;
   q.push(x);
 }
 while(!q.empty())
 {
   st.push(q.front());
   q.pop();
 }
 while(!st.empty())
 {
   q.push(st.top());
   st.pop();
 }
 while(!q.empty())
 {
   cout<<q.front()<<" ";
   q.pop();
 }

}
