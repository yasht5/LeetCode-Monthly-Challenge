class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s;
        for(int i=0,j=0, t=0; j<nums.size();j++)
        {
            while(s.find(nums[j])!=s.end()){
                s.erase(nums[i]);
                t-=nums[i];
                i++;
            }
            s.insert(nums[j]);
            t+=nums[j];
            res = max(res, t);
        }
        return res;
    }
};
