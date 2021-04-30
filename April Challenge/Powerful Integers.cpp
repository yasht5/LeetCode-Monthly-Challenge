class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int a = x==1 ? bound : (int)(log10(bound)/log10(x));
        int b = y==1 ? bound : (int)(log10(bound)/log10(y));
        
        set<int> s;
        for(int i=0;i<=a;i++)
        {
            for(int j=0;j<=b;j++)
            {
                int val = pow(x, i) + pow(y, j);
                if(val <= bound)
                {
                    s.insert(val);
                }
                
                if(y==1)
                {
                    break;
                }
            }
            if(x==1)
            {
                break;
            }
        }
        vector<int> res(s.begin(), s.end());
        
        return res;
    }
};
