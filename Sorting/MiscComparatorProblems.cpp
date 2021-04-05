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
bool comp(pp &a, pp &b)
{
  if(a.first!=b.first)     //if the element are not same then normal comaprison as it is stable
  {
    return a.first< b.first;
  }
  //if 2 elements are same then their indicies will be respected
  return a.second<b.second;
}
void respectingIndexSort(int a[], int n)
{
  vpp arr;
  for(int i=0;i<n;i++)
  {
    arr.pb({a[i],i});
  }
  sort(arr.begin(),arr.end(),comp);
  for(auto x:arr)
  {
    cout<<x.first<<" ";
  }
}
bool cmp(pair<int,pp> &a, pair<int ,pp> &b)
{
  //check for frequency
  if(a.second.second!=b.second.second)
  {
    return a.second.second<b.second.second;
  }
  //chek if freq==same and then ele same
  if(a.first!=b.first)
  {
    return a.first<b.first;
  }
  //else if both above cond is true then we will return on the basis of index
  return a.second.first<b.second.first;
}
void sortingBasedonFrequency(int a[], int n)
{
  //Criteria of sorting
  //if freq are equal then smaller ele should come first
  //if freq are equal and element are also same then smaller index ele should come first
  //eg: 5 5 7 2 2 --> 7 2 2 5 5
  //parameter for comparator: value,index,freq of element
  vector<pair<int,pp>>arr;
  //frequency of the array
  mp freq;
  for(int i=0;i<n;i++)
    freq[a[i]]++;

  for(int i=0;i<n;i++)
  {
    arr.pb({a[i],{i,freq[a[i]]}});
  }
  for(auto x:arr)
  {
    cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<" "<<endl;
  }
  cout<<"............This is the partition Line........\n";
  sort(arr.begin(),arr.end(),cmp);
  for(auto e:arr)
  {
    cout<<e.first<<" ";
  }

}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
  cin>>a[i];
//respectingIndexSort(a,n);
sortingBasedonFrequency(a,n);
}
