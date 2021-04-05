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
//Check if the pair whose sum==k exist or not.
bool find(vi &v, int &k)
{
    int i=0,j=v.size()-1;
    while(i<j)
    {
        if(v[i]+v[j]==k)
        {
            return true;
        }
        else if(v[i]+v[j]<k)
        {
            i++;
        }
        else
        {
            j--;
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
     if(find(v,k))
     {
         cout<<"Yes"<<endl;
     }
     else cout<<"No"<<endl;
 }

}
