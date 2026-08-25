class Solution {
public:

    int helper(vector<vector<vector<int>>>& dp, vector<int>& prices, int buy, int index, int cap){
        if(index==prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[index][buy][cap]!=-1){
            return dp[index][buy][cap];
        }
        if(buy){
            dp[index][buy][cap] = max(-prices[index]+helper(dp,prices,0,index+1,cap),helper(dp,prices,1,index+1,cap));
        }
        else{
            dp[index][buy][cap] = max(prices[index]+helper(dp,prices,1,index+1,cap-1),helper(dp,prices,0,index+1,cap));
        }
        return dp[index][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(dp,prices,1,0,2);
    }
};