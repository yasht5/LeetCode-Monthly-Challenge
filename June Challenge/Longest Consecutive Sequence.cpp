class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums)
        {
            s.insert(x);
        }
        
        int max_len = 0;
        
        for(int x: nums)
        {
            if(s.find(x-1)==s.end())
            {
                int curr = x;
                int len = 1;
                
                while(s.find(curr+1)!=s.end())
                {
                    len++;
                    curr+=1;
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
        
    }
};
