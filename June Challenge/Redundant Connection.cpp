class Solution {
public:
    vector<int> par;
    int find(int x)
    {
        if(par[x]==-1)
        {
            return x;
        }
        return find(par[x]);
    }
    
    void uni(int x, int y)
    {
        x = find(x);
        y = find(y);
        
        if(x!=y)
        {
            par[x] = y;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par = vector<int>(n+1,-1);
        for(auto e : edges)
        {
            int x = find(e[0]);
            int y = find(e[1]);
            
            if(x==y)
            {
                return {e[0], e[1]};
            }
            uni(x, y);
        }
        return {};
    }
    
};
