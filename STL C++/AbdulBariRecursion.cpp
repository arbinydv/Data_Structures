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
//Types of Recursion
 // Tail Recursion :-> recursive funt is calling at the last statement then its tail func called at last
 // Head Recursion :-> recursive funct is calling at the first and then all processing after the func is called.
 // Tree Recursion :-> recursive funct is calling which creates nodes of diff func calls 0(2^n)
 // Indirect Recursion :-> recursive fucnt is calling forming a cycle.
int func(int n)
{
  static int x=0;
  if(n>0)
  {
    x++;
    return func(n-1)+x;
  }
  return 0;
}
void solve()
{
  int r;
  cin>>r;
  cout<<func(r);
}
int summation(int n)
{
  if(n==0) return 0;
  return summation(n-1)+n;
}
void sumofNnumbers()
{
  int n;
  cin>>n;
  cout<<summation(n)<<endl;
}
void bubblesort()
{
   vi v={8,5,7,3,2};
   for(int i=0;i<5;i++)
   {
     for(int j=0;j<5-i;j++)
     {
       if(v[j]>v[j+1])
          swap(v[j],v[j+1]);
     }
   }
   for(auto e:v)
      cout<<e<<" ";
  cout<<endl;
}
void insertionSort()
{
  vi v={3,4,2,1,7,6,9};
  int n= v.size();
  for(int i=1;i<n;i++)
  {
    int insert= v[i];
    int j=i-1;
    while(j>=0 && v[j]>insert)
    {

      v[j+1]=v[j];
      j--;
    }
    v[j+1]=insert;
  }

  for(int a: v)
    cout<<a<<" ";
}
int Partition(vi &v, int low, int high)
{

  //taking first element as a pivot and placing the pivot at its correct position
  int pivot= v[low];
  int i=low,j=high;
  while(i<j)
  {
  while(pivot>=v[i])
  {
  i++;
  }
  while(pivot<v[j]) j--;
  if(i<j)
    swap(v[i],v[j]);
 }
 swap(v[low],v[j]);
 return j;
}
void Qsort(vi &v, int low, int high)
{
  if(low<high)
  {
    int j= Partition(v,low, high);
    Qsort(v, low, j);
    Qsort(v,j+1,high);
  }
}
void Quicksort()
{
    vi v= {3,4,2,1,7,6,9,17,14,12};
    Qsort(v,0,v.size()-1);
    for(auto it:v)
            cout<<it<<" ";
    cout<<endl;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 //solve();
 //sumofNnumbers();
 //bubblesort();
 //insertionSort();
 //Quicksort();


}
