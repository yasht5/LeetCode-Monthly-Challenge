class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return ksum(nums, target, 0, 4);
    }
private:
    vector<vector<int>> ksum(vector<int> &nums, int tar, int start, int k){
        vector<vector<int>> res;
        if(start==nums.size() || nums[start]*k > tar || tar>nums.back()*k){
            return res;
        }
        if(k==2)
            return twosum(nums, tar, start);
        for(int i = start;i<nums.size();i++){
            if(i==start || nums[i-1]!=nums[i]){
                for(auto &set : ksum(nums, tar-nums[i], i+1, k-1)){
                    res.push_back({nums[i]});
                    res.back().insert(res.back().end(), set.begin(), set.end());
                }
            }
            
        }
        return res;
    }
    vector<vector<int>> twosum(vector<int>& nums, int target, int start) {
        vector<vector<int>> res;
        unordered_set<int> s;
        for (auto i = start; i < nums.size(); ++i) {
            if (res.empty() || res.back()[1] != nums[i])
                if (s.count(target - nums[i]))
                    res.push_back({ target - nums[i], nums[i]});
            s.insert(nums[i]);
        }
        return res;
    }
};
