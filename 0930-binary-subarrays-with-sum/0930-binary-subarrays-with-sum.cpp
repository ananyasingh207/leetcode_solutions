class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n = nums.size();
        int atMost = 0;
        int j = 0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[j];
                j++;
            }
            atMost += i-j+1;
        }
        return atMost;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};