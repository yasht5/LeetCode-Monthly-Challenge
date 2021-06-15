class Solution {
public:
    vector<int> v;
    int n;
    bool solve(int idx, int tar, vector<int> &arr)
    {
        if(idx>=n)
        {
            return v[0]==v[1] && v[1]==v[2] && v[2]==tar;
        }
        for(int i=0;i<4;i++)
        {
            if(v[i]+arr[idx]>tar)
            {
                continue;
            }
            v[i]+=arr[idx];
            if(solve(idx+1, tar, arr))
            {
                return true;
            }
            v[i]-=arr[idx];
        }
        return false;
    }
    
    bool makesquare(vector<int>& arr) {
        n = arr.size();
        v = vector<int>(4);
        if(n==0)
        {
            return false;
        }
        int x= 0;
        for(int i=0;i<n;i++)
        {
            x+=arr[i];
        }
        if(x%4)
        {
            return false;
        }
        sort(arr.rbegin(), arr.rend());
        return solve(0, x/4, arr);
    }
};
