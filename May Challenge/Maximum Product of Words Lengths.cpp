class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(n==0 || n<2)
        {
            return 0;
        }
        vector<int> v(n, 0);
        
        for(int i=0;i<n;i++)
        {
            for(char c : words[i])
            {
                v[i] = v[i] | (1<<(c-'a'));
            }
        }
        int res = 0;
        for(int i=0;i<n-1;i++)
        {
            for(int j = i+1; j<n;j++)
            {
                if((v[i] & v[j]) == 0)
                {
                    int x = words[i].size() * words[j].size();
                    res = max(res, x);
                }
            }
        }
        return res;
        
    }
};
