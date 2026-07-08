class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int oddCount = 0;
        int atMostk = 0;
        int atMostkminus = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1) oddCount++;
            while(oddCount>k){
                if(nums[j]%2==1) oddCount--;
                j++;
            }
            atMostk+=i-j+1;
        }
        oddCount = 0;
        j = 0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1) oddCount++;
            while(oddCount>k-1){
                if(nums[j]%2==1) oddCount--;
                j++;
            }
            atMostkminus+=i-j+1;
        }
        return atMostk-atMostkminus;
    }
};