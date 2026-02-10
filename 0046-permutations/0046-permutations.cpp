class Solution {
public:

    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& permutation, int index, unordered_map<int , bool>& visited){
        if(permutation.size()==nums.size()){
            ans.push_back(permutation);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[nums[i]]){
                permutation.push_back(nums[i]);
                visited[nums[i]]=true;
                helper(nums,ans,permutation,i+1,visited);
                visited[permutation.back()]=false;
                permutation.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> permutation;
        unordered_map<int , bool> visited;
        helper(nums,ans,permutation,0,visited);
        return ans;
    }
};