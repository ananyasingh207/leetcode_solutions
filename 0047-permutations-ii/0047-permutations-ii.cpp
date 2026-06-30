class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, int index, int n){
        if(index==n-1){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=index;i<n;i++){
            if(st.count(nums[i])) continue;
            st.insert(nums[i]);
            swap(nums[i],nums[index]);
            helper(nums,ans,index+1,n);
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        helper(nums,ans,0,n);
        return ans;
    }
};