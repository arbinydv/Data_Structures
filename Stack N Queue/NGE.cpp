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
void solve()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int nge[n];
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while((!st.empty()) && (arr[st.top()]<arr[i]))
        {
           // st.pop();
            nge[st.top()]= arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        nge[st.top()]= -1;
        st.pop();
    }
    for(int j=0;j<n;j++)
        cout<<nge[j]<<" ";
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
     solve();
     cout<<endl;
 }


}
