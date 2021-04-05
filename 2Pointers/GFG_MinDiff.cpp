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
int mindiff(vi &a, vi &b, vi &c)
{
  //need to find the minimum value of exp: max(a[i],b[i],c[i])-min(a[i],b[i],c[i])
  int i=0,j=0,k=0;    //3 pointers
  int minsofar=maxx;
  while(i<a.size() && j<b.size() && k<c.size())
  {
    int x= min({a[i],b[j],c[k]});   // minimum of 3 element in 3 arrays
    int leftover= max({a[i],b[j],c[k]})-x;
    //update the anser
    if(leftover<minsofar)
      minsofar=leftover;
    //pointer movement : increment the pointer pointing to min element out of 3
    if(a[i]==x)
    {
      i++;
    }
    else if(b[j]==x)
    {
      j++;
    }
    else k++;
  }
  return minsofar;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n1,n2,n3;
 cin>>n1>>n2>>n3;
 vi a(n1),b(n2),c(n3);
 for(int i=0;i<n1;i++)
    cin>>a[i];
 for(int j=0;j<n2;j++)
    cin>>b[j];
 for(int k=0;k<n3;k++)
    cin>>c[k];
 cout<<mindiff(a,b,c);
}
