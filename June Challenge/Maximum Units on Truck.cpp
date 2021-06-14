class Solution {
public:
    
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>&a, vector<int>&b)
        {
            return a[1]>b[1];
        } );
        
        int res = 0;
        for(auto box : boxTypes )
        {
            int x = min(box[0], truckSize);
            res+=(x*box[1]);
            truckSize-=x;
            if(!truckSize)
            {
                break;
            }
        }
        return res;
    }
};
