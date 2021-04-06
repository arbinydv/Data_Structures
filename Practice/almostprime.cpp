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
bool isPrime(int n)
{
    // check if the number if prime or not

    for(int i=2; i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }

    return true;

}
int32_t main()
{
    FAST           
    #ifndef ONLINE_JUDGE

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    
    // get the count of numbers from 1 to n which are almost prime
    // all the number from 1 to 5 cannot be consider as they have only one factors so we start looking 
    // for the number from 6 till n

    int almostPrime=0;
    for(int curr= 6;curr<=n;curr++)
    {
        // check if the curr element is prime or not 
        int divisors= 0;
        for(int i=2;i<curr;i++)
        {
            if(curr%i==0 && isPrime(i))
            {
                divisors++;
                if(divisors>2) break;
            }
            
        }
        if(divisors==2) 
            almostPrime++;
    }

    cout<<almostPrime;
}

