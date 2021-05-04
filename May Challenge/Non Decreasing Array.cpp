class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        int val = INT_MIN;
        if(n==1)
        {
            return 1;
        }
        bool flag = 0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<=nums[i+1])
            {
                val = nums[i];
            }
            else
            {
                if(nums[i+1]<val)
                {
                    nums[i+1] = nums[i];
                }
                count--;
            }
            if(count<0)
            {
                flag=1;
                break;
            }
        }
        if(flag || count<0)
        {
            return 0;
        }
        return 1;
    }
};
