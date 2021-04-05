//This program will check whether array is sorted or not using recursion
#include<bits/stdc++.h>
using namespace std;
bool isSorted(int *a,int n)  // address and size of the array is passed
{
  // base case
  if(n==0 || n==1)  // if array has no element or only 1 element
  {
    return true;
  }
  bool ans= isSorted(a+1,n-1);
  if(a[0]<a[1] && ans==true)  // if condition satisfies and array reaches to its end
  {
    return true;
  }
  else
  {
    return false;
  }
}
int main()
{
  int a[]= {1,3,2,5,6,9,7,4};
  int n=sizeof(a)/sizeof(a[0]);
  bool ans= isSorted(a,n);
  if(!ans)
  {
    cout<<"unsorted";
  }
  else
  {
    cout<<"Sorted";
  }
}
