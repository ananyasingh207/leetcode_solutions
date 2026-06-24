class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1){
            return n;
        }
        sort(nums.begin(),nums.end());
        int maxCount = 1;
        int count = 1;
        int j = 1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        for(int i=1;i<j;i++){
            if(nums[i-1]+1==nums[i]){
                count++;
            }
            else{
                count=1;
            }
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};