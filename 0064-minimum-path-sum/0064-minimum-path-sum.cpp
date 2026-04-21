class Solution {
public:
    int getSum(vector<vector<int>>& grid, int n, int m, int r, int c, vector<vector<int>>& dp){
        if(r>n-1 || c>m-1){
            return 100000;
        }
        if(r==n-1 && c==m-1){
            dp[r][c]=grid[r][c];
            return dp[r][c];
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int right = grid[r][c]+getSum(grid,n,m,r,c+1,dp);
        int down = grid[r][c]+getSum(grid,n,m,r+1,c,dp);
        dp[r][c]=min(right,down);
        return dp[r][c];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return getSum(grid,n,m,0,0,dp);
    }
};