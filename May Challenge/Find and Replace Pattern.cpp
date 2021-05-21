class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        for(string s: words){
            if(match(s, pattern)){
                res.push_back(s);
            }
        }
        return res;
    }
    
    bool match(string s, string patt){
        map<char, char> m1, m2;
        for(int i=0;i<s.size();i++){
            if(m1.find(s[i])==m1.end()){
                m1[s[i]] = patt[i];
            }
            if(m2.find(patt[i])==m2.end()){
                m2[patt[i]] = s[i];
            }
            if(m1[s[i]]!=patt[i] || m2[patt[i]]!=s[i]){
                return false;
            }
            
        }
        return true;
    }
};
