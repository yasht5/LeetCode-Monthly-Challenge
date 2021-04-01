class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ret;
        bool ok = true;
        int n = stamp.size();
        int tsz = 0;
        while (ok) 
        {
          ok = false;
          int x = 0;
          for (int sz = stamp.size(); sz > 0; sz--) 
          {
            for (int i = 0; i <= stamp.size() - sz; i++) 
            {
               string newStamp = string(i, '*') +
               stamp.substr(i, sz) + string(stamp.size() - sz - i, '*');
               int pos = target.find(newStamp);
               while (pos != string::npos) 
               {
                  ok = true;
                  x += sz;
                  ret.push_back(pos);
                  fill(target.begin() + pos, target.begin() +
                  pos + stamp.size(), '*');
                  pos = target.find(newStamp);
               }
            }
         }
         tsz += x;
      }
      reverse(ret.begin(), ret.end());
      return tsz == target.size() ? ret : vector<int>();
    }
};
