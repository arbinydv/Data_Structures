//Today, I will prepare and someday my chance will come. ~A.lincoln
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pb push_back
#define maxx INT_MAX
#define minn INT_MIN
#define N 10005
#define endl "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
        if(n==0) return 0;
        
        int max_profit=0;
        
        int min_so_far[n];
         min_so_far[0]= prices[0];
        
        for(int left= 1;left<n;left++)
        {
            min_so_far[left]= min(min_so_far[left-1],prices[left]);
            
        }
        
        int max_so_far[n];
        
        max_so_far[n-1]= prices[n-1];
        
        for(int right=n-2;right>=0;right--)
        {
            max_so_far[right]= max(max_so_far[right+1],prices[right]);
        }
        
        for(int i=0;i<n;i++)
        {
            max_profit= max(max_profit,max_so_far[i]-min_so_far[i]);
        }
        
        return max_profit;
    }
};
int32_t main()
{
           FAST           
    #ifndef ONLINE_JUDGE

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n; cin>>n;
    vi prices(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    
    Solution soln;
    cout<< soln.maxProfit(prices);

    return 0;
}







