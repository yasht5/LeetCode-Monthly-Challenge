class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size()-k;
        vector<int> res(k);
        while(l<r)
        {
            int m = l + (r-l)/2;
            if(x - arr[m] > arr[m+k]-x)\
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        for(int i=0;i<k;i++)
        {   
            res[i] = arr[l+i];
        }
        return res;
    }
};
