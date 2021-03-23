class Solution {
public:
    
    int mod  = 1000000007;
    
    int threeSumMulti(vector<int>& arr, int target) {
        map<int, int> mp;
        
        int n = arr.size();
        long res=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(mp.find(target-arr[i]-arr[j])!=mp.end())
                {
                    res+=1L*mp[target-arr[i]-arr[j]];
                }
            }
            mp[arr[i]] = mp[arr[i]]+1;
        }
        
        return (int )(res%mod);
    }
};
