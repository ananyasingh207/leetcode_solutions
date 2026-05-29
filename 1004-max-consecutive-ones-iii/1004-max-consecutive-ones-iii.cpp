class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeroCount = k;
        int maxLen = 0;
        int i=0, j=0;
        while(j<n){
            if(nums[j]==0){
                zeroCount--;
            }
            while(zeroCount<0){
                if(nums[i]==0){
                    zeroCount++;
                }
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};