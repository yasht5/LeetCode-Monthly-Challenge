class Solution {
public:
    
    int n, m;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
         n = matrix.size();
         if(n==0)
        {
            return res;
        }
        m = matrix[0].size();
        
        if(m==0)
            return res;
        vector<vector<bool>> atlantic(n, vector<bool>(m, 0));
        vector<vector<bool>> pacific(n, vector<bool>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            bfs(matrix, i, 0, pacific);
            bfs(matrix, i, m-1, atlantic);
        }
        for(int i=0;i<m;i++)
        {
            bfs(matrix, 0, i, pacific);
            bfs(matrix, n-1, i, atlantic);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;    
    }
    
private:
    void bfs(vector<vector<int>> &matrix, int i, int j, vector<vector<bool>> &vis)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        
        vector<pair<int, int>> dir;
        dir.push_back({0, 1});
        dir.push_back({1, 0});
        dir.push_back({0, -1});
        dir.push_back({-1, 0});
        
        vis[i][j]=1;
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int curr = matrix[p.first][p.second];
            for(int k=0;k<4;k++)
            {
                int r = p.first + dir[k].first;
                int c = p.second + dir[k].second;
                
                if(r>=0 && r<n && c>=0 && c<m && curr <= matrix[r][c] && !vis[r][c])
                {
                    q.push({r, c});
                    vis[r][c]=1;
                }
            }
            
        }
    }
    
};
