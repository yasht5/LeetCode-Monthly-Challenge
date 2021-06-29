class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCnt = 0;
        int i = 0;
        int maxLen = 0;
        for(int j=0; j<nums.size(); j++)
        {
            if(nums[j]==0)
            {
                zeroCnt++;
            }
            while(zeroCnt > k)
            {
                if(nums[i]==0)
                {
                    zeroCnt--;
                }
                i++;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};
