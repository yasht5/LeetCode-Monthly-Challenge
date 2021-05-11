class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int i = 0, j = n-k;
        int total = 0;
        for(i=j;i<n;i++)
        {
            total+=v[i];
        }
        int ans = total;
        i=0;
        while(k--)
        {
            ans = max(ans, total+=v[i++]-v[j++]);
        }
        return ans;
    }
};
