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
bool isPossible(int books[], int n, int m, int mid)
{
  int student_count=1;
  int sum=0;
  for(int i=0;i<n;i++)
  {
    if(sum+books[i]>mid)
    {
      sum=books[i];
      student_count++;
      if(student_count>m) return false;
    }
    else
    {
      sum+=books[i];
    }
  }
  return true;
}
int findpage(int books[], int n, int m)
{
  if(m>n) return -1;
  int low=0;
  int high= 0;
  int temp=0;
  for(int i=0;i<n;i++)
  {
    temp+=books[i];
    low=max(low,books[i]);
  }
  high=temp;
  int page=low;
  while(low<=high)
  {
    int mid= (low+high)/2;
    if(isPossible(books, n,m,mid))
    {// exist then check for smaller values of mid in the left bound so that we can get the min values of book allocation
      page= mid;
      high=mid-1;
    }
    else
    {
      low= mid+1;
    }
  }
  return page;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   int n;
   cin>>n;
   int books[n];
   for(int i=0;i<n;i++) cin>>books[i];
   int m;
   cin>>m;
    cout<<findpage(books, n,m)<<endl;
 }
}
