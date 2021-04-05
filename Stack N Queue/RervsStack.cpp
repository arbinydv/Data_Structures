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
void pushbottom(int x, stack<int>&st)
{
  if(st.empty()) {  st.push(x);  return; }
  int y= st.top();
  st.pop();
  pushbottom(x,st);
  st.push(y);
}
void reverse(stack<int>&st)
{
  if(st.empty())
  {
    return;
  }
  int temp= st.top();
  st.pop();
  reverse(st);
  pushbottom(temp,st);
}
void print(stack<int>st)
{
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 //Reversing stack using recursion
 stack<int>st;
 int n; cin>>n;
 while(n--)
 {
   int x;cin>>x;
   st.push(x);
 }
 cout<<"Original Content:\n";
 print(st);
 reverse(st);
 cout<<"\nReversal Content:\n";
 print(st);
}
