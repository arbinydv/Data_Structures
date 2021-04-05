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
//Count of pairs with given sum
//it will includes all the elements which are repeated as well
//includes frequency and combinations ko concept as well
//eg: 1 4 4 5 5 5 6 6 11  k=10
//all pairs: {4,6},{4,6},{4,6},{4,6},{5,5},{5,5},{5,5}
int countpairs(vi &v, int &k)
{
    int i=0,j=v.size()-1;
    int counter=0;
    while(i<j)
    {
        if(v[i]+v[j]>k)
        {
            j--;
        }
        else if(v[i]+v[j]<k)
        {
            i++;
        }
        else
        {
          // if we get the sum which pointer to increase next ??
          int c1=0,c2=0;
          int p=v[i], q= v[j];
          //getting the frequency
          while(v[i]==p)
          {
            i++;
            c1++;
          }
          while(v[j]==q)
          {
            j--;c2++;
          }
          //for the case like 5 5 5 5
          if(p==q)
          {
            //combinations
            int temp= j-i+1;
            counter+= (temp*(temp+1))/2;
          }
          else
            counter+=c1*c2;
        }
    }
    return counter;
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
     int res=countpairs(v,k);
     cout<<res;
 }

}
