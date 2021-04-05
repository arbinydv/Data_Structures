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
int removeDuplicates(vector<int>& nums) {

  int i= 1,j=1;  //two pointers
  int maxallowance =2;  // so that we can count the occurence of kunaii element
  int count=1;
  while(j<nums.size())
  {
    if(nums[j-1]!=nums[j])   // if the element is not same then simply place it earlier
    {
      nums[i++]= nums[j];
    }
    else
    {
      if(count<maxallowance)
      {
        nums[i++]=nums[j];
        count++;
      }
      else{
        count=1;
      }
    }
    j++;
  }
  return i;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 vi nums={1,1,1,2,2,3};
 int resized= removeDuplicates(nums);
 for(auto x:nums)
    cout<<x<<" ";
}
