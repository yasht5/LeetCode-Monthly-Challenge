    class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        priority_queue<int> pq;
        
        for(int i=0; i<n-1;i++)
        {
            int d = heights[i+1] - heights[i];
            
            if(d>0)
            {
                if(ladders>0)
                {
                    pq.push(-d);
                    ladders--;
                }
                else if(!pq.empty() && d > -pq.top())
                {
                    pq.push(-d);
                    bricks+=pq.top();
                    pq.pop();
                }
                else
                {
                    bricks-=d;
                }
                if(bricks<0)
                {
                    return i;
                }
            }
        }
        return n-1;
        
    }
};
