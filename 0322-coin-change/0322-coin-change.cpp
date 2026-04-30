class Solution {
public:
    int inf = 1e9;
    int minCoins(vector<int>& coins, int n, int amount, int index,vector<vector<int>>& dp){
        if(index>=n){
            return inf;
        }
        if(amount<0){
            return inf;
        }
        if(amount==0){
            return 0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int pick = 1+minCoins(coins,n,amount-coins[index],index,dp);
        int nonpick = minCoins(coins,n,amount,index+1,dp);
        dp[index][amount] = min(pick,nonpick);
        return dp[index][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = minCoins(coins,n,amount,0,dp);
        return (ans==inf ? -1 : ans);
    }
};