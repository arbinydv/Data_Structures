#define ll long long
class Solution {
 ll getvalue(ll mid, ll n)
 {
   ll value= 1;
   for(int i=1;i<n;i++)
   {
     value=value*mid+1;
   }
   return value;
 }

 ll bsearch(ll num, int i)
 {
   ll low= pow(n,1./i);
   ll high= pow(k,1./(i-1));
   if(i==2) high=k;
   while(low<=high)
   {
     ll mid=low+(high-low)/2;
     ll x= getvalue(mid,i);
     if(x>k)
      high=mid-1;
    else if (x<k)
      low= mid+1;
    else return mid;
   }
   return -1;
 }
public:
    string smallestGoodBase(string n) {

        //convert string to long long int

        ll numb= stoll(n);
        for(int i=64;i>0;i--)
        {
          ll m = bsearch(numb,i);
          if(m>=2)
            return to_string(check);
        }
        return to_string(numb-1);
    }
};
