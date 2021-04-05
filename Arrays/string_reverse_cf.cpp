#include<bits/stdc++.h>
using namespace std;
int main()
{
   // store the frequencies in array to calculate the freq
  //step1: calculate the prefix sum  of the given integer of m and store
  // them  in arr of size s/2
  // step2: if modulo by 2==0 then no need to swap else swap the given char
  string s;cin>>s;
  int m;cin>>m;
  int n=s.size();
  int h;
  if(n%2==0)
  h=n/2;
  else
  h=n/2+1;
  int arr[h]={0};
  while(m--)
  {
    int l;cin>>l;
    l--;
    arr[l]++;
  }
  for(int i=1;i<h;i++)
  arr[i]+=arr[i-1];
  int temp[h]={};
  for(int i=0;i<h;i++)
  {
    temp[i]=arr[i]%2;
  }
  for(int i=0;i<h;i++)
  {
    if(temp[i]>0)
    {
      swap(s[i],s[n-i-1]);
    }
  }
  cout<<s;
}
