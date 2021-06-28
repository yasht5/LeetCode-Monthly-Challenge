class Solution {
public:
    string removeDuplicates(string s) {
        //stack<char> st;
        string res="";
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if(res.size() && s[i]==res.back())
            {
                res.pop_back();
            }
            else
            {
                res+=s[i];
            }
        }
        return res;
    }
};
