#include<bits/stdc++.h>
using namespace std;
#define int long long int
int f[100];
const int mufasa= 1000003;
void factorial()
{
    f[0]=1;
    f[1]=1;

    int fact=1;
    for(int i=2;i<=15;i++)    // at most it could go till sixteen length
    {
        fact =((fact % mufasa)*(i % mufasa) % mufasa);
        f[i]=fact;
    }

}
int32_t main()
{
    //store factorial of all the number in array which will goes till lenght of the string
    int t;cin>>t;
    factorial();
    while(t--)
    {
        string s;cin>>s;
        string s2;
        s2=s;
        sort(s.begin(),s.end());
        //checking for the repeated character;
        bool flag=false;
        for(int i=1;i<s.size();i++)
        {
            if(s[i-1]==s[i])
            {
              flag=true;
              break;
            }
        }
        if(flag) cout<<"0\n";

        //store the rank 0f each character in the given string
        else
        {
        int rank[26]={0};
        for(int i=0;i<s.size();i++)
        {
           rank[s[i]-'a']=i;

        }
        // now doing the combinatorics to get the rank of the given string
        int r=0;
        for(int i=0;i<s2.size();i++)
        {
            int temp= s2[i]-'a';
            r= (r + (rank[temp]*(f[s2.length() - i - 1]))%mufasa)%mufasa;
	        for(int j = temp; j < 26; j++){
	            rank[j]--;
	        }
        }
        r++;
        cout<<r<<endl;
    }
    }
}
