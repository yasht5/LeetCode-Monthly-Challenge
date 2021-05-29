class Solution {
public:
    
    int res = 0;
    vector<bool> cols, diag, antidia;
    
    int totalNQueens(int n) {
        cols = vector<bool> (n);
        diag = vector<bool> (2*n);
        antidia = vector<bool> (2*n);
        backtrack(0, n);
        return res;
    }
    
    void backtrack(int row, int n)
    {
        if(row == n)
        {
            res++;
        }
        for(int i=0;i<n;i++)
        {
            int d = row - i + n;
            int aD = row+i;
            
            if(cols[i] || diag[d] || antidia[aD])
            {
                continue;
            }
            cols[i] = true;
            diag[d] = true;
            antidia[aD] = true;
            backtrack(row+1, n);
            cols[i] = false;
            diag[d] = false;
            antidia[aD]  = false;
        }
    }
};
