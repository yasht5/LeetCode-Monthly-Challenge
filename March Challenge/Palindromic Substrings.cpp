class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count =0;
        if(n==0)
            return count;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            count++;
        }
        for(int i=1;i<n;i++)
        {
            if(s[i-1]==s[i])
            {
                dp[i-1][i]=1;
                count++;
            }
            
        }
        for(int j=2;j<n;j++)
        {
            for(int i=0;i<j;i++)
            {
                if(dp[i+1][j-1] && s[i]==s[j])
                {
                    dp[i][j]=1;
                    count++;
                }
            }
        }
        return count;
    }
};
