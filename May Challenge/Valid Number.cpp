class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i=0;
        while(s[i]==' ')
            i++;
        if(i==n)
            return false;
        if(s[i]=='+' || s[i]=='-')
            i++;
        int num_dig, num_point;
        for(num_dig = 0, num_point=0; (s[i]<='9' && s[i]>='0') || s[i]=='.'; i++)
        {
            if(s[i]=='.')
            {
                num_point++;
            }
            else
            {
                num_dig++;
            }
        }
        if(num_point>1 || num_dig <1 )
            return false;
        
        if(s[i] == 'e' || s[i] == 'E') 
        {
            i++;
            if (s[i] == '+' || s[i] == '-') i++; // skip the sign

            num_dig = 0;
            while (s[i] >= '0' && s[i] <= '9') 
            { 
                i++; 
                num_dig++;
            }

            if (num_dig < 1)
                return false;
            
        }
        while (s[i] == ' ') 
        {
            i++;
        }
        return i==n;
    }
};
