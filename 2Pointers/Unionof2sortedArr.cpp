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
//Union of 2 sorted Arrays using Two pointer approach
void findUnion(int arr1[],int arr2[],int n, int m)
{
  //vector to store the joined elements in sorted fashion
  vi ans;
  int i=0,j=0,same;
  while(i<n && j<m)
  {
    //if ele in arr1 is smaller then push it and move i till the last
    //occurence of the element so that we avoid duplicates
    if(arr1[i]<arr2[j])
    {
      ans.push_back(arr1[i]);
      same=arr1[i];
      i++;
      //move i to the next diff element
      while(i<n && arr1[i]==same)
      {
        i++;
      }
    }
    //if arr2[j] is greater then do as above
    else if(arr1[i]>arr2[j])
    {
      ans.push_back(arr2[j]);
      same=arr2[j];
      j++;
      while(j<m && arr2[j]==same)
        j++;
    }
    //if the element is same then we push it and increase both pointers till next diff element isnot found.
    else
    {
      ans.push_back(arr1[i]);
      same= arr1[i];
      i++;j++;
      while(i<n && arr1[i]==same){
        i++;
      }
      while(j<m && arr2[j]==same)
        j++;
    }
  }
  //left over elements too will follow the same approach
  while(i<n)
  {
    ans.push_back(arr1[i]);
    same= arr1[i];
    i++;
    while(i<n && arr1[i]==same){i++;}
  }
  while(j<m)
  {
    ans.push_back(arr2[j]);
    same= arr2[j];
    j++;
    while(j<m && arr2[j]==same){j++;}
  }
  for(auto it:ans)
    cout<<it<<" ";
  cout<<endl;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;
 cin>>t;
 while(t--)
 {
   int n,m;
   cin>>n>>m;
   int arr1[n],arr2[m];
   for(int i=0;i<n;i++)
      cin>>arr1[i];
   for(int j=0;j<m;j++)
      cin>>arr2[j];
    findUnion(arr1,arr2,n,m);
    cout<<endl;
  }
}
