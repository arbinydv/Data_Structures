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
bool prime(int n)
{
  for(int i=2;i<=sqrt(n);i++)
  {
    if(n%i==0) return false;
  }
  return true;
}
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 int n;cin>>n;
 int total=0;
 	for(int i = 6; i <= n; i++){
 	  	int count = 0;
 		for(int j = 2; j < i; j++){
 			if(i % j == 0 && prime(j)){
 				    count++;
 				if(count>2) break;
 			}
 		}
 		if(count==2) total++;
 	}
 	cout<<total;
}
