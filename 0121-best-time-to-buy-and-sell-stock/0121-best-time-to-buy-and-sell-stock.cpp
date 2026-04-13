class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]<minPrice) minPrice = prices[i];
            else{
                int profit = prices[i]-minPrice;
                if(profit>maxProfit) maxProfit = profit;
            }
        }
        return maxProfit;
    }
};