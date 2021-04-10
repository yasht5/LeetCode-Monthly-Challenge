class Solution {
public:
    int max_len;
    int n, m;
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        max_len =1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int len = dfs(matrix, i, j, dp);
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
private:
    pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp)
    {
        if(dp[i][j]!=0)
        {
            return dp[i][j];
        }
        int res=1;
        for(pair<int, int> p : dir)
        {
            int x = i + p.first;
            int y = j + p.second;
            if(x<0 || x>=n || y<0 || y>=m || matrix[x][y] <= matrix[i][j])
            {
                continue;
            }
            int len = 1 + dfs(matrix, x, y, dp);
            res = max(res, len);
        }
        dp[i][j] = res;
        return res;
    }
};
