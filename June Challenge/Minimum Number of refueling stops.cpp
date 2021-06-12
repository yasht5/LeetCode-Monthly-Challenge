class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i=0;
        int ans;
        priority_queue<int> pq;
        
        for(ans=0; startFuel<target;ans++)
        {
            while(i<stations.size() && stations[i][0]<=startFuel)
            {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())
            {
                return -1;
            }
            startFuel+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
