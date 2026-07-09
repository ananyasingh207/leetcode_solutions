class Solution {
public:
    int atMost(vector<int>& nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        int j = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            while(freq.size()>k){
                freq[nums[j]]--;
                if(freq[nums[j]]==0){
                    freq.erase(nums[j]);
                }
                j++;
            }
            count+=i-j+1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};