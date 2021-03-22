class Solution {
public:
    
    int mod = 1000000007;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int res=0;
        
        vector<long long> dp(n, 1);
        map<int, int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    int idx = arr[i]/arr[j];
                    
                    if(mp.find(idx)!=mp.end())
                    {
                        dp[i] = (dp[i] + (dp[j]%mod)*(dp[mp[idx]]%mod))%mod;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            res = (res + dp[i])%mod;
        }
        
        
        return res%mod;
    }
};
