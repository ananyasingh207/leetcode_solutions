class Solution {
public:
    int getSum(vector<vector<int>>& grid, int n, int m, int r, int c, vector<vector<int>>& dp){
        if(r>n-1 || c>m-1){
            return INT_MAX;
        }
        if(r==n-1 && c==m-1){
            dp[r][c]=grid[r][c];
            return dp[r][c];
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int right = getSum(grid,n,m,r,c+1,dp);
        int down = getSum(grid,n,m,r+1,c,dp);
        int best = min(right,down);
        if(best == INT_MAX){
            dp[r][c]=INT_MAX;
            return dp[r][c];
        }
        dp[r][c] = best+grid[r][c];
        return dp[r][c];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return getSum(grid,n,m,0,0,dp);
    }
};