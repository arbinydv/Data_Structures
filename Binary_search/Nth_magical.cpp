#define ll long long int
#define mufasa 1000000007
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {

        ll x= A;
        ll y=B;

        //get lcm
        ll lc= (x*y)/__gcd(x,y);
        ll low=1;
        ll high= y*N;  // for safety we can say it will go uptp 10^18
        ll ans=0;
        while(low<=high)
        {
            ll mid= (low+high)/2;
            ll temp= mid/x+ mid/y - mid/lc;
            if(temp<N)
            {
                low=mid+1;
            }
            else
            {
                if(temp==N)
                {
                    ans= mid;
                    high=mid-1;
                }
                else
                {
                    high= mid-1;
                }
            }

        }
        return ans%mufasa;
    }
};
