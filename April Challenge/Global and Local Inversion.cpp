class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int max_val = 0;
        int n = A.size();
        for(int i=0; i < n-2; ++i)
        {
            max_val = max(max_val, A[i]);
            
            if(max_val > A[i+2])
            {
                return false;
            }
        }
        return true;
    }
};
