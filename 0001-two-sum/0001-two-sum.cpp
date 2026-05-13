class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
        for(int i=0;i<n;i++){
            int key = target - nums[i];
            auto it = mp.find(key);
            if(it!=mp.end()){
                int j = it->second;
                if(i!=j){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};