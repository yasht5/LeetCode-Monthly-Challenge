class Solution {
public:
    string toLowerCase(string s) {
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if('a'<=s[i] && s[i]<='z')
            {
                continue;
            }
            else if('A'<=s[i] && s[i]<='Z')
            {
                s[i]+=32;
            }
        }
        return s;
    }
};
