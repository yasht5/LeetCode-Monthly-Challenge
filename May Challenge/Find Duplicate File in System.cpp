class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for(string s: paths)
        {
            string temp="";
            int i=0;
            for(i=0;i<s.size() && s[i]!=' ';i++)
            {
                temp+=s[i];
            }
            temp+='/';
            i++;
            while(i<s.size())
            {
                string file="", t="";
                while(i<s.size() && s[i]!='(')
                {
                    t+=s[i];
                    i++;
                }
                while(i<s.size() && s[i]!=' ')
                {
                    file+=s[i];
                    i++;
                }
                m[file].push_back(temp+t);
                i++;
            }
        }
        for(auto it = m.begin();it!=m.end();it++)
        {
            if(it->second.size() > 1)
            {
                res.push_back(it->second);
            }
        }
        return res;
    }
};
