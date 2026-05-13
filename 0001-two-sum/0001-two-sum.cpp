class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        while(i<nums.size()){
            int j = i+1;
            int key = target - nums[i];
            while(j<nums.size()){
                if(nums[j]==key){
                    return {i,j};
                }
                j++;
            }
            i++;
        }
        return {};
    }
};