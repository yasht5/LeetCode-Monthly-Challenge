class Solution {
public:
    
    int x = pow(3, 19);
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        return x%n==0;
    }
};
