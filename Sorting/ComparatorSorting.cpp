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

//Program to show the use of comparator function for sorting
bool comparator(int a, int b)    //this will sort the array in ascending order
{
  return a<b;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int arr[]={2,4,3,1,5,6,5};
 int n=sizeof(arr)/sizeof(arr[0]);
 sort(arr,arr+n,comparator);
 for(int a:arr)
    cout<<a<<"  ";
}
