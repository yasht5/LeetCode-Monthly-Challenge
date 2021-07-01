class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        
        for(int i=0;i<n;i++)
        {
            int sz = res.size();
            
            for(int j = sz-1;j>=0;j--)
            {
                int c = res[j] | 1<<i;
                res.push_back(c);
            }
        }
        return res;
    }
};
