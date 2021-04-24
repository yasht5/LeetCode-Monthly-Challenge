class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> graph;
    
    vector<int> disc, low, par;
    
    int t = 0;
    
    void dfs(int u)
    {
        disc[u] = low[u] = t++;
        int s = graph[u].size();
        for(int i=0;i<s;i++)
        {
            int v = graph[u][i];
            if(disc[v]==-1)
            {
                par[v] = u;
                dfs(v);
                
                if(low[v] > disc[u])
                {
                    res.push_back({u, v});
                }
                
                low[u] = min(low[u], low[v]);
            }
            else if(v!=par[u])
            {
                low[u] = min(low[u], low[v]);
            }
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph = vector<vector<int>>(n);
        par = vector<int> (n, -1);
        low = vector<int> (n, -1);
        disc = vector<int> (n, -1);
        
        for(auto c : connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(disc[i]==-1)
            {
                dfs(i);
            }
        }
        return res;
    }
};
