class Solution {
public:
    const long long int mod = 1000000007;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int d1 = max(horizontalCuts[0], h - horizontalCuts.back());
        int d2 = max(verticalCuts[0], w - verticalCuts.back());
        
        for(int i=1;i<horizontalCuts.size();i++)
        {
            d1 = max(d1, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();i++)
        {
            d2 = max(d2, verticalCuts[i]-verticalCuts[i-1]);
        }
        
        return (int)(((d1%mod)*(d2%mod))%mod);
    }
};
