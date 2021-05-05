class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0]=0;
        
        for(int i=0, j=1;i<n;i++)
        {
            if(dp[i]==-1)
            {
                return -1;
            }
            while(j<n && j-i<=nums[i])
            {
                dp[j]=dp[i]+1;
                j++;
            }
        }
        return dp[n-1];
    }
};
