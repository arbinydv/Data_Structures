#include<bits/stdc++.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
#define int long long int
#define vi vector<int>
#define pp pair<int,int>
#define form for(int i=0;i<n;i++)
#define se set<int>
#define pb push_back
#define mp map<int,int>
#define max INT_MAX
#define min INT_MIN
void rearrange(vector<int>&arr)
{
  int n=arr.size();
  vi temp(n);
  for(int i=0;i<n;i++)
  {
    temp[arr[i]]=i;
  }
  for(auto x:temp) cout<<x<<" ";
}
void optmized(vector<int>&arr)
{
  // first increase all the values bty 1;
  int n=arr.size();
  for(int i=0;i<n;i++)
  {
    arr[i]++;
  }
  // checking for the cycle
  for(int i=0;i<n;i++)
  {
    if(arr[i]<0) continue;
    else
    {
       int value= -(i+1);
        i= arr[i]-1;
        while(arr[i]>0)
        {
          int temp= arr[i]-1;
          arr[i]= value;
          value= -(i+1);
          i=temp;
        }
    }
  }
  for(int i=0;i<n;i++)
  {
    arr[i]=(-arr[i])-1;
  }
  for(auto x:arr) cout<<x<<" ";


}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 vi arr(n);
 for(int i=0;i<n;i++)
 {
   cin>>arr[i];
 }
 rearrange(arr);

 optmized(arr);
}
