class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        if(n<2)
            return 0;
        int buy = -prices[0] - fee;
        int sell = 0;
        
        for(int i=1; i<prices.size();i++)
        {
            int lastbuy = buy;
            buy = max(buy, sell - prices[i] - fee);
            sell = max(sell, lastbuy + prices[i]);
            
        }
        
        return sell;
    }
};
