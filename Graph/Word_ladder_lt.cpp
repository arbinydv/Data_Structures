#include<bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
        int n=wordList.size();
        if(n==0)
            return 0;
        
        bool start,end;
        start=end=false;

        unordered_set<string>set;
        for(int i=0;i<n;i++)
        {
            if(beginWord.compare(wordList[i])==0)
                start=true;
            if(endWord.compare(wordList[i])==0)
                end=true;
            set.insert(wordList[i]);
        }
        
        if(!end)
            return 0;
        
        queue<string>q;
        q.push(beginWord);

        int level=0;
        while(!q.empty())
        {
            level++;
            int sz= q.size();

            while(sz--)
            {
                string curr= q.front();
                q.pop();

                // checking all possible combination of the string

                for(int i=0;i<curr.size();i++)
                {
                    string temp= curr;
                    for(char x='a';x<='z';x++)
                    {
                        temp[i]=x;
                        if(curr.compare(temp)==0)   // same word so skip
                            continue;
                        
                        if(temp.compare(endWord)==0)
                            return level+1;
                        if(set.find(temp)!=set.end())  // present
                        {
                           q.push(temp);
                           set.erase(temp);
                        }
                    }

                }
            }
        }
        return 0;
}

bool connected(string&s1,string  &s2)
{
    int cnt=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i])
            cnt++;
    }
    if(cnt==1)
        return true;
    return false;
}

int ladderlen(string begin, string end, vector<string>&wordList)
{
    int n=wordList.size();
    if(n==0)
    return 0;

    bool present=false;
    bool bpresent=false;
    int start=0;
    for(int i=0;i<n;i++)
    {
        if(end.compare(wordList[i])==0)
            present=true;
        if(begin.compare(wordList[i])==0)
        {
            start=i;
            bpresent=true;
        }
    }

    if(!present)
        return 0;
    
   
    vector<bool>visited(n+1,false);

    // creating adjacency list

  // if start lies in suitable range
    vector<int>adj[n+1];

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(connected(wordList[i],wordList[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // if start==n
    if(start==n)
    {
        for(int i=0;i<n;i++)
        {
            if(connected(begin,wordList[i]))
            {
                adj[n].push_back(i);
                adj[i].push_back(n);
            }
        }
    }
    
    visited[start]=true;
    queue<pair<int,int>>q;
    q.push({start,0});

    int dist=-1;
    while(!q.empty())
    {
       pair<int,int>p= q.front();
       q.pop();

       if(end.compare(wordList[p.first])==0)
       {
           dist=p.second;
          break;
       }

       //BFS calls

       for(auto it:adj[p.first])
       {
           if(!visited[it])
           {
               q.push({it,p.second+1});
               visited[it]=true;
           }
       }
    }
    if(dist==-1) return 0;
    return dist+1;

}
int main()
{
    string s1="hit";
    string s2="cog";
    vector<string>wordList({"hot","dot","dog","lot","log","cog"});

    // Method 1: using set to store the strings and then applying all the possible combination of string from 'a' to 'z' and checking if the combination is present or not

    int ans1= ladderLength(s1,s2,wordList);

    // Method 2: SPOJ prime path method
    int ans2= ladderlen(s1,s2,wordList);
    cout<<ans2;

}