class Solution {
public:

    void helper(vector<int>& candidates, int target, int index, int sum, vector<vector<int>>& ans, vector<int>& combination){
        if(sum==target){
            ans.push_back(combination);
            return;
        }
         if(sum>target || index==candidates.size()){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;

            if(sum+candidates[i]>target){
                break;
            }
            combination.push_back(candidates[i]);
            helper(candidates,target,i+1,sum+candidates[i],ans,combination);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,0,ans,combination);
        return ans;
    }
};