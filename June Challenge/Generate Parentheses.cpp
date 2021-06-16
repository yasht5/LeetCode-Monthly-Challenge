class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        res.clear();
        solve("", n, 0);
        return res;
    }
    
    void solve(string s, int n, int m)
    {
        if(n==0 && m==0)
        {
            res.push_back(s);
            return;
        }
        if(m>0)
        {
            solve(s+")", n, m-1);
        }
        if(n>0)
        {
            solve(s+"(", n-1, m+1);
        }
    }
};
