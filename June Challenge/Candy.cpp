class Solution {
public:
    
    int sumN(int n)
    {
        return n*(n+1)/2;
    }
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<=1)
        {
            return n;
        }
        int res = 0;
        int up = 0, down=0, slope = 0;
        for(int i=1;i<n;i++)
        {
            int newSlope = ratings[i]>ratings[i-1] ? 1 : (ratings[i] < ratings[i-1] ? -1 : 0);
            if(slope > 0 && newSlope == 0 || slope<0 && newSlope>=0)
            {
                res+=sumN(up)+sumN(down)+max(up, down);
                up=0;
                down=0;
            }
            if(newSlope > 0)
            {
                up++;
            }
            else if(newSlope<0)
            {
                down++;
            }
            else
            {
                res++;
            }
            slope = newSlope;
        }
        res+=sumN(up)+sumN(down)+max(up, down)+1;
        return res;
    }
};
