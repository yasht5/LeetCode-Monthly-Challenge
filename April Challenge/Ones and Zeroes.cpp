class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int numzero, numone;
        
        for(string s : strs)
        {
            numzero=0;
            numone =0;
            for(char c : s)
            {
                if(c=='0')
                {
                    numzero++;
                }
                else
                {
                    numone++;
                }
            }
            
            for(int i=m;i>=numzero;i--)
            {
                for(int j=n;j>=numone;j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i-numzero][j-numone]+1);
                }
            }
        }
        return dp[m][n];
    }
};
