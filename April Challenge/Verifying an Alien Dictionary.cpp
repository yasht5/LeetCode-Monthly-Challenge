class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;
        for(int i=0;i<order.length();i++)
        {
            mp[order[i]]=i;
        }
        
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                if(j>=words[i+1].length())
                {
                    return false;
                }
                if(words[i][j]!=words[i+1][j])
                {
                    char cur = words[i][j];
                    char nxt = words[i+1][j];
                    
                    if(mp[cur]>mp[nxt])
                    {
                        return false;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return true;
    }
};
