/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.


*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> dp(n+1, false);
        int sum_rqd = n*(n+1)/2;
        int sum=0;
        int rqd_num=0;
        for(int i=0;i<n;i++)
        {
            if(dp[nums[i]]==false)
            {
                sum+=nums[i];
                dp[nums[i]]=true;
            }
            else
            {
                rqd_num = nums[i];
            }
        }
        
        vector<int> res;
        res.push_back(rqd_num);
        res.push_back(sum_rqd - sum);
        return res;
    }
};
