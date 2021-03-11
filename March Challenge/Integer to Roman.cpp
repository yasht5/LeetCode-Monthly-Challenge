class Solution {
public:
    
    int num_hep[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    string help[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    
    string intToRoman(int num) {
        string ans="";
        int i=12;
        
        while(num>0)
        {
            int div = num/num_hep[i];
            num = num%num_hep[i];
            
            while(div--)
            {
                ans+=help[i];
            }
            i--;
        }
        return ans;
    }
};
