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
    int n,k;
    cin>>n>>k;
    vi arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int prefsum=0;
    unordered_map<int ,int >ump;
    ump.insert({prefsum,-1});
    int maxlength=0;
    for(int i = 0;i<n;i++)
    {
        prefsum+=arr[i];
        //insertion in map
        if(ump.find(prefsum)==ump.end())
        {
            ump[prefsum]=i;
        }

        //search for the sum K exist or not
        if(ump.find(prefsum-k)!= ump.end())
        {
            maxlength= max(maxlength,i-ump[prefsum-k]);
        }
    }
    cout<<maxlength<<endl;
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
