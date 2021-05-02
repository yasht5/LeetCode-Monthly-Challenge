class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto &a, auto &b){return a[1]<b[1];});
        priority_queue<int> pq;
        int total = 0;
        for(auto &c : courses)
        {
            int dir = c[0], end = c[1];
            if(dir+total <= end)
            {
                total+=dir;
                pq.push(dir);
            }
            else if(pq.size() && pq.top()>dir)
            {
                total+=dir - pq.top();
                pq.pop();
                pq.push(dir);
            }
        }
        return pq.size();
        
    }
};
