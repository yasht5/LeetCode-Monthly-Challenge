class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int> inc(n, 1);
        vector<int> ans(n, 1);
        int res=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    inc[i]=max(inc[i], inc[j]+1);
                    ans[i]=max(ans[i], inc[i]);
                }
            }
            res=max(res, ans[i]);
        }
        return res;
    }
};
