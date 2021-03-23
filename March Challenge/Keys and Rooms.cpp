class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        set<int> vis;
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            
            vis.insert(x);
            
            for(int i: rooms[x])
            {
                if(vis.find(i)==vis.end())
                {
                    q.push(i);
                }
            }
        }
        
        return vis.size() == rooms.size();
    }
};
