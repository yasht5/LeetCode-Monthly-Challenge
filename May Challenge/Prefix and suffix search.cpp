class WordFilter {
public:
    map<string, int> mp;
    
    WordFilter(vector<string>& words) {
       int n = words.size();
        for(int i=0;i<n;i++)
        {
            string w = words[i];
            int m = w.size();
            
            for(int j=1;j<=m;j++)
            {
                string p = w.substr(0, j);
                for(int k=0; k<m; k++)
                {
                    string s = w.substr(k, m);
                    mp[p+"|"+s] = i+1;
                }
            }
        }
    }
    
    int f(string pre, string suf) {
        string s = pre + "|" + suf;
        return mp[s]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
