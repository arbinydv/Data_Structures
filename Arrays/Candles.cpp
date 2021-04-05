#include<bits/stdc++.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
#define int long long int
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t;cin>>t;
 while(t--)
 {
   int n; cin>>n;
   int k=2;


   while(1)
   {
     int res= pow(2,k)-1;
     if(n%res==0)
     {
       cout<<n/res<<endl;
       break;
     }
     k++;
   }

 }

}
