class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int next = 0;
        int nextNext = 0;
        for(int i=n-1;i>=0;i--){
            ans = max(nums[i]+nextNext,next);
            nextNext = next;
            next = ans;
        }
        return ans;
    }
};