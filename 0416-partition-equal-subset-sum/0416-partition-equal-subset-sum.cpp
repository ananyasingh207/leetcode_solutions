class Solution {
public:

    vector<vector<int>> dp;

    int partitionSum(vector<int>& nums, int target, int index){
        if(target==0){
            return 1;
        }
        if(index==nums.size() || target<0){
            return 0;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int include = partitionSum(nums,target-nums[index],index+1);
        int exclude = partitionSum(nums,target,index+1);
        dp[index][target] = exclude || include;
        return dp[index][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        sum=sum/2;
        dp.resize(nums.size(),vector<int>(sum+1,-1));
        partitionSum(nums,sum,0);
        return partitionSum(nums,sum,0);
    }
};