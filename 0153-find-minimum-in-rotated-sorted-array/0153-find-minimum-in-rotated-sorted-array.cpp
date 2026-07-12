class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];
        for(int i=0;i<nums.size();i++){
            mini = min(mini,nums[i]);
        }
        return mini;
    }
};