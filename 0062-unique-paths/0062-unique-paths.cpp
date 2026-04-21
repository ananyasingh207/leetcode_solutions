class Solution {
public:
    int getPaths(int n, int m, int r, int c, vector<vector<int>>& dp){
        if(r==n-1 && c==m-1){
            dp[r][c] = 1;
            return dp[r][c];
        }
        if(r>n-1 || c>m-1){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int right = getPaths(n,m,r,c+1,dp);
        int down = getPaths(n,m,r+1,c,dp);
        dp[r][c] = right + down;
        return dp[r][c];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return getPaths(n,m,0,0,dp);
    }
};