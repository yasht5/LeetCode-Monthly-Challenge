class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.length();
        vector<string> res;
        for(int i=1;i<n-2;i++)
        {
            //string t1 = ;
            //string t2 = s.substr(i+1, n-2-i);
            vector<string> a = solve(s.substr(1, i));
            vector<string> b = solve(s.substr(i+1, n-2-i));
            for(auto &c1 : a)
            {
                for(auto &c2 : b)
                {
                    res.push_back("(" + c1 + ", "+ c2+ ")");
                }
            }
        }
        return res;
    }
    
    vector<string> solve(string s)
    {
        int n = s.size();
        if(n==0 || (n>1 && s[0]=='0' && s[n-1]=='0'))
        {
            return {};
        }
        if(n>1 && s[0]=='0')
        {
            return {"0."+s.substr(1)};
        }
        if(n==1 || s[n-1]=='0')
        {
            return {s};
        }
        vector<string> ans = {s};
        for(int i=1;i<n;i++)
        {
            ans.push_back(s.substr(0, i)+'.'+s.substr(i));
        }
        return ans;
    }
};
