class Solution {
public:
    
    bool isSub(string a, string b)
    {
        int i=0, j=0;
        int m = a.length();
        int n = b.length();
        
        while(i<m && j<n)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return j==n;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        unordered_map<string, int> mp;
        
        for(string s : words)
        {
            mp[s]++;
        }
        
        for(auto i = mp.begin(); i!=mp.end();i++)
        {
            if(isSub(s, i->first))
            {
                res+=i->second;
            }
        }
        return res;    
    }
};
