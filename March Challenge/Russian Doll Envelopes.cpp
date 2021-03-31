class Solution {
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        if(envelopes.size()==0)
            return 0;
        int n = envelopes.size();
        vector<int> h(n);
        for(int i=0;i<n;i++)
        {
            h[i] = envelopes[i][1];
        }
        
        return lis(h);
    }
    
private:
    int lis(vector<int> v)
    {
        int piles = 0, n = v.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++)
        {
            int key = v[i];
            int left = 0, right = piles;
            while(left < right)
            {
                int mid = (left+right)/2;
                if(temp[mid]>=key)
                {
                    right = mid;
                }
                else
                {
                    left = mid+1;
                }
            }
            if(left == piles)
            {
                piles++;
            }
            temp[left]=key;
        }
        return piles;
    }
};
