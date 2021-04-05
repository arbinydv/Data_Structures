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
int32_t main()
{
           FAST           
    #ifndef ONLINE_JUDGE

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    // print the sum of an array having n elements

    int n; cin>>n;
    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    cout<<"The Sum of elements of an array is : "<<sum<<endl;


    return 0;
}

