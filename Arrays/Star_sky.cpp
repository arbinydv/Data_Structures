//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
int32_t main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 //C. star sky codeforces
 // I liked one of the solution and the code was very clean
 int n,q,c;
 cin>>n>>q>>c;
 //creating 3d matrix to store the cnt of stars with initial brightness
 vector<vector<vector<int>>> cnt_of_stars(c+1,vector<vector<int>>(101,vector<int>(101)));
 while(n--)
 {
   int x,y,s;   // x-pos, y-pos, initial brightness==s of a star
   cin>>x>>y>>s;
   cnt_of_stars[s][x][y]++;
 }
 //finding the total brightness of a star using cummulative sum technique school level S(AUB)
 // in 2d matrix cummulative sum of whole array is a[x][y]=a[x][y]+a[x-1][y]+a[x][y-1]-a[x-1][y-1];
 //in 3d matrix we can get by simply running an outer loop s(AUBUC)

for(int i_bright=0;i_bright<c+1;i_bright++)   // brightness cannto be more than c so we take modulo
{
  int p= i_bright;
  for(int x= 1;x<101;x++)   // given x and y pos of the star
  {
    for(int y=1;y<101;y++)
     cnt_of_stars[p][x][y]= cnt_of_stars[p][x][y]+cnt_of_stars[p][x-1][y]+cnt_of_stars[p][x][y-1]-cnt_of_stars[p][x-1][y-1];
  }
}
while(q--)
{
  int t,x1,y1,x2,y2;
  cin>>t>>x1>>y1>>x2>>y2;                // brightness at t of a star in rect.axis
  int ans=0;
  for(int i_brightness=0;i_brightness<c+1;i_brightness++)
  {
    int pos= i_brightness;
    int new_brightness_of_each_star= (i_brightness+t)%(c+1);
    //taking common s(aubuc complement)
    int count_of_stars= cnt_of_stars[pos][x2][y2]-cnt_of_stars[pos][x2][y1-1]-cnt_of_stars[pos][x1-1][y2]+cnt_of_stars[pos][x1-1][y1-1];
    ans+=count_of_stars*new_brightness_of_each_star;
  }
  cout<<ans<<endl;
}


}
