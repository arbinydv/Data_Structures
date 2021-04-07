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
    bool charmatch(int freqs1[], int freqs2[])
    {
        for(int i=0;i<26;i++)
        {
            if(freqs1[i]!= freqs2[i])
             return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {

        // write a function to return true if s2 contains the permutation of s1.
        // In other words, one of the first string's permutations is the substring of the second string.

        // second string s2 contains the permutation of s1 
        // we will use sliding window concept where window_size==s1.size(0) and check if the freq of char at s2 matches with s1 or not

        if(s1.size()>s2.size()) return false;

        int freqs1[26]={0};   // stores the freq of smaller string s1
        int freqs2[26]= {0};  // stores the freq of larger string s2 till the size of s1 

        for(int i=0;i<s1.size();i++)
        {
            freqs1[s1[i]-'a']++;
            freqs2[s2[i]-'a']++;
        }

        // we will check for the character match and its frequency match  if the char is diff we will remove
        // the preceding character from window and add sucedding char freq in the window freq2 
         
        for(int i=0;i<s2.size()-s1.size();i++)
        {
            if(charmatch(freqs1,freqs2))
                return true;
            
            // add curr char
            freqs2[s2[i+s1.size()]-'a']++;
            // else we will remove the previous char for freq2

            freqs2[s2[i]-'a']--;

        }

        return charmatch(freqs1,freqs2);
        
    }
};
int32_t main()
{
           FAST           
    #ifndef ONLINE_JUDGE

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s1,s2;
    cin>>s1>>s2;
    Solution sln;

    cout<<sln.checkInclusion(s1,s2)<<endl;

    return 0;
}

