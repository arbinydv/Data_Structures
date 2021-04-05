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
// find the count of all subarrays whose sum is divisible by k
// find the count of pref[sum]%k==0 repetition 
// T.C= O(n)+ O(k) 
// Best  whiteboard explanation by George Chrys Leetcode after Vivek sir 
// Essential tescases: [-4,-1,5,5] k=2 here if we don't take -ve into +ve remainder 
// we will miss the chace of [5,5] which in fact is 10%2==0 

int32_t main()
{
    int n,k;
    cin>>n>>k;
    vi arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    vi freq(k,0);
    freq[0]= 1; // to store first subarray whose sum%k==0

    int pref=0;
    int count=0;

    for(int i=0;i<n;i++)
    {
        pref+=arr[i];

        int rem= pref%k;

        if(rem<0)
        {
            // using euclidian concept when remainder is negative we add the remainder with  K to 
            // make the remainder positive
            rem+=k;
        }
        // counting the subarrays whose remainder%k has repeated and stored in array

        count+=freq[rem];
        freq[rem]++;
    }

    cout<<count<<endl;

}

