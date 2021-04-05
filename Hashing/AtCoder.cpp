//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long int
#define vi vector<int>
#define pp pair<int,int>
#define se set<int>
#define pb push_back
#define ump unordered_map<int,int>
#define maxx INT_MAX
#define minn INT_MIN
#define endl "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
int32_t main()
{
    FAST
    int n; cin>>n;
    ump freq;
    for(int i=0;i<n;i++)
    {
        int temp; cin>>temp;
        freq[temp]++;
    }

    int count=0;
    for(auto it:freq)
    {
        if(it.second<it.first)
            count+=it.second;
        if(it.second>it.first)
            count+=(it.second-it.first);
        else count+=0;
    }
    cout<<count<<endl;
}

