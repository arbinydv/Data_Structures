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
// Rearrange Positive and Negative element Problem  don't care about the relative position
void Rearrange(vi &v, int &left, int &right)
{
  int n=v.size();
  while(left<=right)
  {
    while(left<=n-1 && v[left]>=0)   // keep moving towards right till its Positive element
    {
      left++;
    }
    while(right>=0 && v[right]<0)   // keep moving towards left till a Positive element is not encntred.
    {
      right--;
    }
    //at junction swap left,right
    if(left<right)
    {
      swap(v[left],v[right]);
    }
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 vi v={12,11,-13,-5,6,-7,5,-3,-6};
 int left=0;
 int right= v.size()-1;
 Rearrange(v,left,right);
 //print -ve at first and then Positive  here realativity is not maintained.
 reverse(v.begin(),v.end());
 for(auto i:v)
 {
   cout<<i<<" ";
 }

}
