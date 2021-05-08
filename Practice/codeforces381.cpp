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

    int n; cin>>n;
    vi arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    int start=0, end= n-1;
    int seeraj=0,dima=0;
    int CurrMax= minn;
    int turn= 0;
    while(start<=end)
    {
        // getting the max first 
        if(arr[start]>=arr[end])
        {
            CurrMax= arr[start];
            start++;
        }
        else
        {
            CurrMax= arr[end];
            end--;
        }
        // checking whose turn is it starting from sheeraj so it's initial is 0

        if(turn%2==0)
            seeraj+=CurrMax;
        else dima+=CurrMax;
        turn++;
    }

    cout<<seeraj<<" "<<dima;

    return 0;
}

