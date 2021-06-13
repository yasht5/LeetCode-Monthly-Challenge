class Solution {
public:
    
    bool isPalindrome(string str){
        int i = 0;
        int j = str.size() - 1; 

        while(i < j)
        {
            if(str[i++] != str[j--]) 
                return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> res;
        
        for(int i=0;i<words.size();i++)
        {
            string s = words[i];
            reverse(s.begin(), s.end());
            mp[s] = i;
        }
        
        if(mp.find("")!=mp.end())
        {
            for(int i=0;i<words.size();i++)
            {
                if(i==mp[""])
                {
                    continue;
                }
                if(isPalindrome(words[i]))
                {
                    res.push_back({mp[""], i});
                }
            }
        }
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                string l = words[i].substr(0, j);
                string r = words[i].substr(j);
                
                if(mp.find(l)!=mp.end() && isPalindrome(r) && mp[l]!=i)
                {
                    res.push_back({i, mp[l]});
                }
                
                if(mp.find(r)!=mp.end() && isPalindrome(l) && mp[r]!=i)
                {
                    res.push_back({mp[r], i});
                }
                
            }
        }
        return res;
    }
    
};
