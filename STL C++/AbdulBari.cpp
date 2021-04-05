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
int arr[]={4,8,10,15,18,21,24,27,29,33,34,37,39,41,43};
int RecursiveBinarySearch(int key, int low, int high);
void BinarySearch()
{
  int n= sizeof(arr)/sizeof(arr[0]);
  int key= 24;
  cout<<RecursiveBinarySearch(key,0,n-1);
}
int RecursiveBinarySearch(int key, int low, int high)
{
  if(low<=high)
  {
    int mid= (low+high)>>1;
    if(arr[mid]==key)
      return mid;
    else if(arr[mid]<key)
    {
      return RecursiveBinarySearch(key,mid+1,high);
    }
    else
    {
      return RecursiveBinarySearch(key,low, mid-1);
    }
  }
  return -1;
}
void Duplicatesinstring()
{
  //use of bitwise masking to find the duplicates in the string
  string s; cin>>s;

  int state=0,shifted=0;  // state is the charac in string masked in 32 bits memory
                          //shifted is used to check if the char is on or off if on then it is repeated
   for(int i=0;i<s.size();i++)
   {
     shifted=1;
     shifted=shifted<<(s[i]-97);   // left shifted by th diff of char-97 and marked one.
     //check if already on or off
     if(state&shifted)
     {
        //yes it is on which means already present
        cout<<"The duplicate is at index : "<<i<<" and the character is: "<<s[i]<<"\n";
     }
     else
     {
       //if not then mark that character with one
       state= state|shifted;    // 0 | 1==1
     }
   }
}
void Anagramchecker()
{
  //to check whether the given 2 strings are anagram or not.   anagram==anay permutation of a given string
  string a,b;
  cin>>a>>b;
  int freq[26]={0};
  for(int i=0;i<a.size();i++)
  {
    freq[a[i]-97]++;
  }
  for(int j=0;j<b.size();j++)
  {
    freq[b[j]-97]--;
  }
  for(int i=0;i<26;i++)
  {
    if(freq[i]>0)
    {
     cout<<"Not an anagram";break;
   }
  }
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
//  BinarySearch();
//  Duplicatesinstring();
//  Anagramchecker();
}
