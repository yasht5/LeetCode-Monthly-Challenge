class Solution {
public:
    string customSortString(string order, string str) {
        vector<int>cnt(128, 0);
        for(char c: str)
        {
            cnt[c]++;
        }
        int i=0;
        for(char c : order)
        {
            while(cnt[c])
            {
                str[i++]=c;
                --cnt[c];
            }
        }
        for(char c = 'a';c<='z';c++)
        {
            while (cnt[c] > 0) {
                str[i++] = c;
                --cnt[c];
            }
        }
        return str;
    }
};
