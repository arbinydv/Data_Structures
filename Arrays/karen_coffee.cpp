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
	int n,k,q;
	cin>>n>>k>>q;
	int a[200002]={0};
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x]++;
		a[y+1]--;
	}
	for(int i=1;i<200002;i++)
	{
		a[i]=a[i]+a[i-1];
	}
	for(int i=0;i<200002;i++)
	{
		if(a[i]>=k)
			a[i]=1;
		else
			a[i]=0;
	}
	for(int i=1;i<200002;i++)
	{
		a[i]=a[i]+a[i-1];
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<a[y]-a[x-1]<<endl;
	}

}
