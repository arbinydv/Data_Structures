#include<bits/stdc++.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
#define ll long long
#define vi vector<int>
#define pp pair<int,int>
#define form for(int i=0;i<n;i++)
#define se set<int>
#define pb push_back
#define mp map<int,int>
#define max INT_MAX
#define min INT_MIN
void insertionsort(int a[],int n)
{
  for(int i=1;i<n;i++)
  {
    int key= a[i];  // 5
    int pachadiko= i-1; // 1-1=0
    while(pachadiko>=0 && a[pachadiko]>key) // 0>==0 && a[0]>a[1]
    {
      swap(a[pachadiko],a[pachadiko+1]);
      pachadiko--;
    }
  }
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
}
int main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 // insertiong sort
 int a[5]={1,1,5,3,2};
 insertionsort(a,5);

}
