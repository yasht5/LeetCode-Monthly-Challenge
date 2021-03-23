class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string num = to_string(N);
        sort(num.begin(), num.end());
        for(int i=0;i<32;i++)
        {
            int n = 1<<i;
            string temp = to_string(n);
            sort(temp.begin(), temp.end());
            if(temp==num)
                return true;
        }
        
        return false;
    }
};
