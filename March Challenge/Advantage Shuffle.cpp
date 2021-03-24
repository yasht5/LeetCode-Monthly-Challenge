class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        multiset<int> mp(A.begin(), A.end());
        
        vector<int> res(n, -1);
        for(int i=0;i<n;i++)
        {
            auto it = mp.upper_bound(B[i]);
            if(it!=mp.end())
            {
                res[i]=(*it);
                mp.erase(it);
            }
        }
        
        auto it = mp.begin();
        for(int i=0;i<n;i++)
        {
            if(res[i]<0)
            {
                res[i] = *it;
                ++it;
            }   
        }
        return res;
    }
};
