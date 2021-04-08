class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if(n==0)
        {
            return {};
        }
        vector<string> res;
        string curr = "";
        
        helper(digits, res, curr, 0);
        return res;
    }
    
private:
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void helper(string& digits, vector<string>& res, string& temp, int idx)
    {
        if(idx == digits.length())
        {
            res.push_back(temp);
            return;
        }
        int x = digits[idx]-'0';
        for(int i=0;i<charmap[x].length(); i++)
        {
            temp.push_back(charmap[x][i]);
            helper(digits, res, temp, idx+1);
            temp.pop_back();
        }
    }
};
