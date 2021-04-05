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
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n,t;
 cin>>n>>t;
 double pyramidglasses[13][13]={0};
 pyramidglasses[1][1]=t;
 int count=0;
 for(int i=1;i<=n;i++)
 {
   for(int j=1;j<=i;j++)
   {
     if(pyramidglasses[i][j]>=1){
      count++;
      pyramidglasses[i+1][j]+=(pyramidglasses[i][j]-1)/2;    //left child
      pyramidglasses[i+1][j+1]+=(pyramidglasses[i][j]-1)/2; //right child

   }
 }
 }
 for(int i=1;i<=n;i++){
   for(int j=1;j<=n;j++)
    cout<<pyramidglasses[i][j]<<" ";
    cout<<endl;
 }
 cout<<count;

}
