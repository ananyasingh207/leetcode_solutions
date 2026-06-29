class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxCount = 0;
        int i = 0;
        while(i<n){
            if(nums[i]==1){
                count++;
            }
            else{
                count = 0;
            }
            maxCount = max(maxCount,count);
            i++;
        }
        return maxCount;
    }
};