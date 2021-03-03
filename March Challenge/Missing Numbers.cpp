/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
	
*/



/*
Naive Approach: 
1) use sorting and then check the first index at which value of arr[i] != i.
2) create a bool dp[n+1] array and store dp[nums[i]] as true. Traverse the dp array and find the element which is false return that index.

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0;
        for(;i<n;i++)
        {
            if(nums[i]!=i)
				return i;
        }
        return i;
    }
};

/*
Optimized solution:
If we carefully read the problem we find that we are given n ditinct numbers and we know that the sum of first n natural numbers is = n(n+1)/2 say sum_rqd.
We will use this concept here. Calculate sum of all elements of the array say sum. The required number is sum_rqd - sum.

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum_rqd = n*(n+1)/2;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        return sum_rqd - sum;
    }
};

