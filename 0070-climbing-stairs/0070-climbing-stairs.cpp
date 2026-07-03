class Solution {
public:
    int solve(int n , vector<int>& dp){
        if(n==0 || n==1 || n==2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int oneStep = solve(n-1,dp);
        int twoStep = solve(n-2, dp);
        dp[n] = oneStep + twoStep;
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};