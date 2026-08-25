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
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        dp[i][buy][cap] = max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }
                    else{
                        dp[i][buy][cap] = max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};