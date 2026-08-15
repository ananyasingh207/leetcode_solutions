/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& allPath){
        if(root==nullptr) return;
        path.push_back(root->val);
        int sum = accumulate(path.begin(),path.end(),0);
        if(sum==targetSum && !root->left && !root->right) allPath.push_back(path);
        solve(root->left,targetSum,path,allPath);
        solve(root->right,targetSum,path,allPath);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPath;
        vector<int> path;
        solve(root,targetSum,path,allPath);
        return allPath;
    }
};