class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        
        unsigned int sum = 0;
        for(int i : target)
        {
            sum+=i;
            pq.push(i);
        }
        
        while(pq.top()!=1)
        {
            int x = pq.top();
            pq.pop();
            sum-=x;
            if(x<= sum || sum<1)
            {
                return false;
            }
            x=x%sum;
            sum+=x;
            pq.push(x);
        }
        return true;
    }
};
