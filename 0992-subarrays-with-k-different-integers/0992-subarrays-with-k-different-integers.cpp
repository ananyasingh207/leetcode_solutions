class Solution {
public:
    int atMostK(vector<int>& nums, int k){
        if (k < 0) return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int count = 0;
        unordered_map<int,int> mp;
        while(l<n && r<n){
            mp[nums[r]]++;
            int distinct = mp.size();
            while(distinct>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
                distinct = mp.size();
                
            }
            count+=(r-l)+1;
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,k) - atMostK(nums,k-1);
    }
};