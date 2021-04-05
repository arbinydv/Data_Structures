#include<bits/stdc++.h>
using namespace std;
void computesum(vector<vector<int> > arr,int n, int m)
{
  int maxsum=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      for(int k=i;k<n;k++)
        for(int l=j;l<m;l++)
        {
          //int temp=0;
        //  cout<<"sub-matrix of size"<<endl;
           for(int p=i;p<=k;p++)
            for(int q=j;q<=l;q++)
            {

            //  temp+=arr[p][q];
            //  maxsum= (temp>maxsum) ? temp:maxsum;
            cout<<arr[p][q]<<" ";
            }
            cout<<endl;
          }

  // return maxsum;
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int> > arr( n , vector<int> (m, 0));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>arr[i][j];
    }
  }
  computesum(arr,n,m);
}
