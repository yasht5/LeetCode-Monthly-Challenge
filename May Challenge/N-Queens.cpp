class Solution {
public:
    vector<vector<string>> res;
    
    bool isValid(vector<string> &board, int row, int col)
    {
        for(int i=row;i>=0;i--)
        {
            if(board[i][col]=='Q')
            {
                return false;
            }
        }
        for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        for(int i = row, j = col; i>=0 && j >= 0; i--, j++)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
                
        }
        return true;
    }
    
    void dfs(vector<string> &board, int row)
    {
        if(row == board.size())
        {
            res.push_back(board);
            return;
        }
        
        for(int i=0;i<board.size();i++)
        {
            if(isValid(board, row, i))
            {
                board[row][i] = 'Q';
                dfs(board, row+1);
                board[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        if(n==0 || n==2 || n==3)
        {
            return {};
        }
        vector<string> currBoard(n, string(n, '.'));
        dfs(currBoard, 0);
        return res;
    }
};
