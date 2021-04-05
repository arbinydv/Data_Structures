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
//Manhattan Distance in Optimal Solution
int distance(int arr[], int n)
{
  sort(arr,arr+n);
  int prefSum[n];
  prefSum[0]=arr[0];
  for(int i=1;i<n;i++)
    prefSum[i]=arr[i]+prefSum[i-1];
  int sum=0;
  for(int i=1;i<n;i++)
  {
    sum+=arr[i]*i-(prefSum[i-1]);
  }
  return sum;
}
int manhattandistance(int x[], int y[], int n)
{
  return distance(x,n)+distance(y,n);  //same approach will be used for calculating the distance
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;
 cin>>n;
 int x[n],y[n];
 for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];

 cout<<manhattandistance(x,y,n)<<endl;
}
