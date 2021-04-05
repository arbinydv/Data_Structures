class Solution {
public:
    vector<string> ans;
    void helper(string s, int index, int count, string temp)
    {
        if(count>=4)
        {
            if(index==s.size())
            {
                ans.push_back(temp);
            }
            return;
        }
        if(index>=s.size())
                return;

        int remLen= s.size()-index;
        for(int i=1;i<=remLen && i<=3;i++)
        {
            string res= s.substr(index, i);
            if(isPossible(res))
            {
                string t=temp;
                if(t=="")
                     t+=res;
                else
                    t=t+'.'+res;
                 helper(s,index+i,count+1,t);

            }
        }
    }
    bool isPossible(string st)
    {

        if(st.size()>1 && st[0]=='0')
            return false;
        int numb= stoi(st);
        return (numb>=0 && numb<=255);

    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12)
        {
            return {};
        }

        helper(s,0,0,"");
        return ans;

    }
};
