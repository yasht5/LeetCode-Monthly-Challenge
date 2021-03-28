class Solution {
public:
    
    string originalDigits(string s) {
        vector <int> cnt(10);
      string ans = "";
      int n = s.size();
      for(int i = 0; i < n; i++){
         if(s[i] == 'z')cnt[0]++;
         if(s[i] == 'w') cnt[2]++;
         if(s[i] == 'g')cnt[8]++;
         if(s[i] == 'x')cnt[6]++;
         if(s[i] == 'v')cnt[5]++;
         if(s[i] == 'o')cnt[1]++;
         if(s[i] == 's')cnt[7]++;
         if(s[i] == 'f')cnt[4]++;
         if(s[i] == 'h')cnt[3]++;
         if(s[i] == 'i') cnt[9]++;
      }
      cnt[7] -= cnt[6];
      cnt[5] -= cnt[7];
      cnt[4] -= cnt[5];
      cnt[1] -= (cnt[2] + cnt[4] + cnt[0]);
      cnt[3] -= cnt[8];
      cnt[9] -= (cnt[5] + cnt[6] + cnt[8]);
      for(int i = 0; i < 10; i++){
         for(int j = 0; j < cnt[i]; j++){
            ans += (char)(i + '0');
         }
      }
      return ans;
    }
};
