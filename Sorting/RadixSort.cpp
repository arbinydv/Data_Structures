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
//Implementation of Radix Sort
int getMax(int arr[],int n)
{
  int temp=arr[0];
  for(int i=0;i<n;i++)
  {
    if(arr[i]>temp)
      temp=arr[i];
  }
  return temp;
}
void countSort(int arr[],int n,int pos)
{
  int modified[n];    // array to store sorted array after every step of radix sortyin
  int freq[10]={0};   // to store digits frequency at Pos place
  for(int i=0;i<n;i++)
    freq[(arr[i]/pos)%10]++;    // gets the remainder according to place from LSB to MSB

  //calculating the cummulative frequency to maintain stability while modification
  for(int i=1;i<10;i++)    // base is 10.
   freq[i]+=freq[i-1];

  //Performing comparsion based sorting of each digits in each call
  for(int i=n-1;i>=0;i--)    // to avoid unstability we are iterating from back
  {
    modified[freq[(arr[i]/pos)%10]-1] = arr[i];   // placing ele
    freq[(arr[i]/pos)%10]--; // decrementing the freq of the digit
  }

  //modification
  for(int i=0;i<n;i++)
    arr[i]=modified[i];
}
void radixsort(int arr[],int n)
{
  int m= getMax(arr,n);  //Getting the max element to find out max no of digits.
// Pos= Places of the digit ones tens hundered for the digit wise sorting
  for(int pos=1;m/pos>0;pos*=10)
  {
    countSort(arr,n,pos);
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int arr[]={170,45,75,90,802,24,2,66};
 int n= sizeof(arr)/sizeof(arr[0]);
 radixsort(arr,n);
 for(int a:arr)
  cout<<a<<" ";
}
