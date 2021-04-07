//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pb push_back
#define maxx INT_MAX
#define minn INT_MIN
#define N 10005
#define endl "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

int minswap(vi & arr, int n, int k)
{
    int win_size=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
            win_size++;
    }

    // counting no of illegal ele in the first window
    int illegal= 0;

    for(int j=0;j<win_size;j++)
    {
        if(arr[j]>k)
            illegal++;
    }

    int minswap= illegal;

    // slinding through windows

    for(int left= 0,right=win_size;right<n;left++,right++)
    {
        if(arr[left]>k)
            illegal--;
        if(arr[right]>k)
            illegal++;
        
        minswap= min(minswap,illegal);
    }
    return minswap;

}
int32_t main()
{
           FAST           
    #ifndef ONLINE_JUDGE

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    // find out the minimum no of swaps required to brings all element <=k together.

    // Concept: find the window size==> count of elem <=k  and then use sliding window

    // In the given window_size  --> total swaps= no of element>k 
    int n; cin>>n;
    vi arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];
    int k; cin>>k;

    int totalswaps = minswap(arr,n,k);

    cout<<totalswaps;

    return 0;
}

