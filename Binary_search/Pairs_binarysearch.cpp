//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long int
#define vi vector<int>
#define pb push_back
// to find only repeating element in the sorted array using Binary Search Technique in logN
int search(vector<int>v,int n)
{
  int left=0,right=n-1;
  while(left<=right)
  {
    int m= (left+right)/2;
    if(v[m]==m+1)
    {
       left= m+1;
    }
    else
    {
      if(v[m]==v[m-1]) return m;
      else right=m-1;
    }
  }
  return -1;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 vi v{1,1,2,3,4,5};
 int indx= search(v,6);
 cout<<v[indx];
}
