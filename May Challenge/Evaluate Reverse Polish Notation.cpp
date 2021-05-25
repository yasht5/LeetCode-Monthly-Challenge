class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        unordered_map<string, function<int (int, int)>> mp = {
            {"+", [](int a, int b){
                return a+b;
            }},
            {"-", [](int a, int b){
                return a-b;
            }},
            {"*", [](int a, int b){
                return a*b;
            }},
            {"/", [](int a, int b){
                return a/b;
            }}
        };
        
        for(string s : tokens)
        {
            if(!mp.count(s))
            {
                st.push(stoi(s));
            }
            else
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                
                st.push(mp[s](y, x));
            }
        }
        return st.top();
        
    }
};
