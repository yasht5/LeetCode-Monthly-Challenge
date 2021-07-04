class Solution {
public:
    const int MOD = 1000000007;
    int countVowelPermutation(int n) {
        long acount=1, ecount=1, icount=1, ocount=1, ucount=1;
        for (int i = 1; i < n; i++) {
            long aCountNew = (ecount + icount + ucount) % MOD;
            long eCountNew = (acount + icount) % MOD;
            long iCountNew = (ecount + ocount) % MOD;
            long oCountNew = (icount) % MOD;
            long uCountNew = (icount + ocount) % MOD;
            acount = aCountNew;
            ecount = eCountNew;
            icount = iCountNew;
            ocount = oCountNew;
            ucount = uCountNew;
        }
        long result = (acount + ecount + icount + ocount + ucount)  % MOD;
        return (int)result;
    }
};
