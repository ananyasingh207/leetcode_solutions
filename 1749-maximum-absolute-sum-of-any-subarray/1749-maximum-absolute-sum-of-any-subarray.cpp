class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int i = 0;
        int sum = 0;
        while(i<n){
            sum+=nums[i];
            maxSum = max(sum,maxSum);
            if(sum<0){
                sum=0;
            }
            i++;
        }
        int minSum = nums[0];
        sum=0;
        i=0;
        while(i<n){
            sum+=nums[i];
            minSum = min(sum,minSum);
            if(sum>0){
                sum=0;
            }
            i++;
        }
        return max(abs(maxSum), abs(minSum));
    }
};