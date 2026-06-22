class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int localMax = nums[0];
        int localMin = nums[0];
        int globalMax = nums[0];
        int globalMin = nums[0];
        for(int i=1;i<n;i++){
            localMax = max(nums[i], nums[i]+localMax);
            localMin = min(nums[i], nums[i]+localMin);

            globalMax = max(globalMax, localMax);
            globalMin = min(globalMin, localMin);
        }
        return max(globalMax, abs(globalMin));
    }
};