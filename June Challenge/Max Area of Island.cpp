class Solution {
public:
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        //this->g = grid;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
    
    int dfs(vector<vector<int>> &g, int x, int y)
    {
        g[x][y] = 2;
        int area = 1;
        for(int i=0;i<4;i++)
        {
            int a = x+dx[i];
            int b = y+dy[i];
            if(a>=0 && a<n && b>=0 && b<m && g[a][b]==1)
            {
                area+=dfs(g, a, b);   
            }
        }
        return area;
    }
};
