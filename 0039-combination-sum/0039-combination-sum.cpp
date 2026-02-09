class Solution {
public:
    set<vector<int>> st;

    void helper(vector<int>& candidates, int i, int target, int sum, vector<vector<int>>& ans, vector<int>& combination){
        if(sum>target || i==candidates.size()){
            return;
        }
        if(sum==target){
            ans.push_back(combination);
            return;
        }
        combination.push_back(candidates[i]);
        helper(candidates,i,target,sum+candidates[i],ans,combination);
        combination.pop_back();
        helper(candidates,i+1,target,sum,ans,combination);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        helper(candidates,0,target,0,ans,combination);
        return ans;
    }
};