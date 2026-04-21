class Solution {
public:
    int getPaths(vector<vector<int>>& obstacleGrid,int n, int m, int r, int c, vector<vector<int>>& dp){
        if(r==n-1 && c==m-1 && obstacleGrid[r][c]!=1){
            dp[r][c] = 1;
            return dp[r][c];
        }
        if(r>n-1 || c>m-1){
            return 0;
        }
        if(obstacleGrid[r][c]==1){
            dp[r][c] = 0;
            return dp[r][c];
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int right = getPaths(obstacleGrid,n,m,r,c+1,dp);
        int down = getPaths(obstacleGrid,n,m,r+1,c,dp);
        dp[r][c] = right+down;
        return dp[r][c];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return getPaths(obstacleGrid,n,m,0,0,dp);
    }
};