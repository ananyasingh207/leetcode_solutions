class Solution {
public:
    bool partition(vector<int>& nums, int n, int index, int sum, int curr_sum, vector<vector<int>>& dp){
        if(index>n-1 || curr_sum>sum){
            return false;
        }
        if(curr_sum==sum){
            return true;
        }
        if(dp[index][curr_sum]!=-1){
            return dp[index][curr_sum];
        }
        bool include = partition(nums,n,index+1,sum,curr_sum+nums[index],dp);
        bool exclude = partition(nums,n,index+1,sum,curr_sum,dp);
        dp[index][curr_sum] = include || exclude;
        return dp[index][curr_sum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        sum=sum/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return partition(nums,n,0,sum,0,dp);
    }
};