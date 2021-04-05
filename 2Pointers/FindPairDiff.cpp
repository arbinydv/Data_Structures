#include<bits/stdc++.h>
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
//find if a[i]-a[j]==k exist or not
//placement of the pointer is at the beginning bcoz it will ensure the difference is found

bool findpairs(vi &v, int &k)
{
    int i=0,j=0;
    while(j<v.size())
    {
      if(v[j]-v[i]==k)
        return true;
      else if(v[j]-v[i]<k)
          j++;
      else
      {
        if(j=i+1)
        {
          i++;
          j++;
        }
        else
        i++;
      }
    }
    return false;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
     int n,k;cin>>n>>k;
     vi v(n);
     for(int i=0;i<n;i++)
        cin>>v[i];
     sort(v.begin(),v.end());
     if(findpairs(v,k))
     {
       cout<<1<<endl;
     }
     else cout<<-1<<endl;
 }

}
