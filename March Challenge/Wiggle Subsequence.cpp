class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int lastsign = 0;
        int length=1;
        
        for(int i=1;i<n;i++)
        {
            int sgn = sig(nums[i]-nums[i-1]);
            if(sgn != lastsign && sgn!=0)
            {
                length++;
                lastsign = sgn;
            }
        }
        return length;
    }
    
    int sig(int n)
    {
        if(n>0)
            return 1;
        if(n<0)
            return -1;
        else
            return 0;
    }
    
};
