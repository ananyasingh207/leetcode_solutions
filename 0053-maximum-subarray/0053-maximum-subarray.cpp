class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum = nums[0];
        int i = 0;
        while(i<n){
            sum = sum + nums[i];
            maxSum = max(maxSum,sum);
            if(sum<0){
                sum=0;
            }
            i++;
        }
        return maxSum;
    }
};