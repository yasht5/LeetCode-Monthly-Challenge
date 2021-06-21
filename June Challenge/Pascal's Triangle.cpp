class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0)
        {
            return res;
        }
        res.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int> v;
            vector<int> prev = res[i-1];
            v.push_back(1);
            for(int j=1;j<i;j++)
            {
                v.push_back(prev[j-1]+prev[j]);
            }
            v.push_back(1);
            res.push_back(v);
        }
        return res;
    }
};
