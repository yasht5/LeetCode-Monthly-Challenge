class Solution {
public:
    map<int, int> mp;
    
    int get(int n )
    {
        int sum = 0;
        while(n>0)
        {
            sum+=mp[n];
            n-= (n&-n);
        }
        return sum;
    }
    void update(int idx, int val, int max) 
    {
        while (idx<=max+1) 
        {
            mp[idx]+=val;
            idx+=(idx&-idx);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if(nums.size()==0)
        {
            return res;
        }
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto x : nums)
        {
            maxi = max(x, maxi);
            mini = min(x, mini);
        }
        int offset = 0;
        if(mini<0)
        {
            offset = -mini;
        }
        maxi+=offset+1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            int n = nums[i] + offset;
            res.push_back(get(n));
            update(n+1, 1, maxi);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    
};
