class Solution {
public:
    int maxAmount(vector<int>& nums, int index, vector<int>& dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int pick = nums[index]+maxAmount(nums,index+2,dp);
        int notpick = maxAmount(nums,index+1,dp);
        dp[index] = max(pick,notpick);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return maxAmount(nums,0,dp);
    }
};