class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            int key = target - nums[i];
            if(mp.find(key)!=mp.end() && mp[key]!=i){
                return {i,mp[key]};
            }
        }
        return {};
    }
};