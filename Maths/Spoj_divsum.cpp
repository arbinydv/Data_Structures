//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long int
int factors(int n)
{
  int sum=0;
  for(int i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      sum+=i;
      int temp= n/i;
      if(temp!=i) sum+=temp;
      else sum+=0;
    }
  }
  return sum-n;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int t; cin>>t;
 while(t--)
 {
   int n;cin>>n;
   if(n==1) cout<<0<<endl;
   else
   {
     cout<<factors(n)<<endl;
   }
 }

}
