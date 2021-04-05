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
#define ump unordered_map<int,int>
#define maxx INT_MAX
#define minn INT_MIN

// THis solution TC=o(max-min) which in case max=10^6 and no of elem=5 then that will take
// a lot of time thus TLE could occur while running 
void getlcs(vi &arr, int &n)
{
    int ans=0,count=0;
    int mn=*min_element(arr.begin(),arr.end());
    int mx= *max_element(arr.begin(),arr.end());

    ump freq;
    for(int a:arr)
    {
        freq[a]++;
    }

    for(int i=mn;i<=mx;i++)
    {
        if(freq.find(i)!=freq.end())
            count++;
        else count=0;
        ans=max(ans,count);
    }
    cout<<ans;

}
void getlcs1(vi &arr, int &n)
{
    int ans=0;
    //streak is the length of longest consecutive element in the arry
    // streal[a[i]]= streak[a[i]-1] + streak[a[i]+1] +1 ;   left boundary+ right boundary+ 1
    ump streak;   // it will store the longest streak at the particular element

    for(int i=0;i<n;i++)
    {
        if(streak[arr[i]])   // the element is already present
        {
            continue; 
        }

        // update the streak of the middle element

        streak[arr[i]]= streak[arr[i]-1]+ 1+ streak[arr[i]+1];
        
        ans= max(ans,streak[arr[i]]);

        // update the border streak of the sequence

        streak[arr[i]-streak[arr[i]-1]]= streak[arr[i]]; // left
        streak[arr[i]+ streak[arr[i]+1]]= streak[arr[i]]; // right
    }

    cout<<ans;
}
void getlcs3(vi &arr, int &n)
{
    ump lcs;
    
    // push all the elements in the map <number, occurence>
    for(int i=0;i<n;i++) lcs[arr[i]]=1;

    int ans=0;
    ump visited;
    for(int i=0;i<n;i++)
    {
        // if arr[i]-1 is present then continue
        if(lcs[arr[i]-1]==1) continue;

        // remove duplicates by checking if ele already marked present
        if(visited[arr[i]]!=0) continue;   // already visited
        
        // mark visited
        visited[arr[i]]=1;

        int strk=0;
        // get the starting position for streak
        int temp= arr[i];
        while(lcs[temp])
        {
            strk++;
            temp++;
        }
        ans= max(ans,strk);
        
    }
    cout<<ans<<endl;


}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;
 cin>>t;
 while(t--)
 {
     int n; cin>>n;
     vi arr(n);
     for(int i=0;i<n;i++) cin>>arr[i];
    // getlcs(arr,n);
     
   //  getlcs1(arr,n);    // optimized LCS method
     cout<<"\n";

     // method 3 
     getlcs3(arr,n);
 }

}