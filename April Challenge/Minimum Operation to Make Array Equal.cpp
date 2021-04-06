class Solution {
public:
    int minOperations(int n) {
        int target = n;
        int res=0;
        for(int i=1;i<=n;i=i+2)
        {
            res+=(target-i);
        }
        return res;
    }
};
