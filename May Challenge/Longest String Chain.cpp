class Solution {
public:
    
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> m;
        
        sort(words.begin(), words.end(), [](const string &s1, const string &s2){
            return s1.size() < s2.size();
        });
        
        int len = 1;
        for(string s : words)
        {
            int l = 1;
            for(int i=0;i<s.size();i++)
            {
                string pre = s.substr(0, i) + s.substr(i+1, s.size()+1);
                if(m.find(pre)!=m.end())
                {
                    int prelen = m[pre];
                    l = max(l, prelen+1);
                }
                
            }
            m[s] = l;
            len = max(len, l);
        }
        return len;
        
    }
};
