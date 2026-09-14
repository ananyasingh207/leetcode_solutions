class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> seen;
        for(int i=0;i<n;i++){
            seen[nums[i]]++;
            if(seen[nums[i]]>1) return true;
        }
        return false;
    }
};