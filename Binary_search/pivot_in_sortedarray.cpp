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
//Leetcode Sorted Array problem
int findpage(int nums[], int n, int d)
{
  if(n==0) return -1;
  int low=0;
  int high= n-1;
  while(low<=high)
  {
    int mid= (low+high)/2;
    if(nums[mid]==d)
    {
      return mid;
    }
    //checking in second half array
    if(nums[mid]<=nums[high])
    {
      if(d>=nums[mid] && d<=nums[high])  // in case targetr is 3  and mid 1 2 3 4
         {
           low= mid+1;
         }
         else
         {
           high=mid-1;
         }
    }
    else
    {
      // finding in first sorted part
      if(nums[low]<=nums[mid])
      {
        if(d>=nums[low] && d<=nums[mid])
        {
          high=mid-1;
        }
        else low=mid+1;
      }
    }
  }
  return -1;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   int n,d;
   cin>>n>>d;
   int nums[n];
   for(int i=0;i<n;i++) cin>>nums[i];
   cout<<findpage(nums, n,d)<<endl;
 }
}
