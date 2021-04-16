class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char , int>> v;
        string res;
        for(char c : s)
        {
            if(v.empty() || v.back().first != c)
            {
                v.push_back({c, 0});
            }
            
            if(++v.back().second == k)
            {
                v.pop_back();
            }
        }
        
        for(auto i : v)
        {
            res.append(i.second, i.first);
        }
        return res;
    }
};
