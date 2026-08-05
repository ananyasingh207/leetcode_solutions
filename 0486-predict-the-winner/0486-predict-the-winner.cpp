class Solution {
public:

    int maxScore(vector<int>& nums, vector<vector<int>>& dp, int i, int j, int n){
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int pickLeft = nums[i]-maxScore(nums,dp,i+1,j,n);
        int pickRight = nums[j]-maxScore(nums,dp,i,j-1,n);
        dp[i][j] = max(pickLeft,pickRight);
        return dp[i][j];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        if(maxScore(nums,dp,0,n-1,n)>=0) return true;
        return false;
    }
};