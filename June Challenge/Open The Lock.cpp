class Solution {
public:
    
    vector<string> convert(string s)
    {
        vector<string> res;
        for(int i=0;i<4;i++)
        {
            string t = s;
            t[i] = (s[i]-'0'+1)%10 + '0';
            res.push_back(t);
            t[i] = (s[i]-'0'-1+10)%10 + '0';
            res.push_back(t);
       }
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> st(deadends.begin(), deadends.end());
        
        unordered_set<string> q1, q2, pass, vis;
        
        string first = "0000";
        
        int res = 0;
        
        if(st.find(first)!=st.end() || st.find(target)!=st.end())
        {
            return -1;
        }
        
        vis.insert("0000");
        
        q1.insert("0000");
        
        q2.insert(target);
        
        while(!q1.empty() && !q2.empty())
        {
            if(q1.size() > q2.size()) 
            {
                swap(q1, q2);
            }
            
            pass.clear();
            
            for(auto s: q1)
            {
                
                if(q2.find(s)!=q2.end())
                {
                    return res;    
                }
                
                vector<string> num = convert(s);
                
                
                for(auto str : num)
                {
                    if(q2.find(str)!=q2.end())
                    {
                        return res+1;    
                    }
                    if(vis.find(str)!=vis.end())
                    {
                        continue;
                    }
                    if(st.find(str)==st.end())
                    {
                        pass.insert(str);
                        vis.insert(str);
                    }
                }
            }
            swap(q1, pass);
            res++;
        }
        return -1;
    }
};
