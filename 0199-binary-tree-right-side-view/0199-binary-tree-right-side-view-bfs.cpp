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

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> eq;
        eq.push(root);
        while(!eq.empty()){
            int n = eq.size();
            for(int i=0;i<n;i++){
                TreeNode* front = eq.front();
                eq.pop();
                if(front->left) eq.push(front->left);
                if(front->right) eq.push(front->right);
                if(i==n-1){
                    ans.push_back(front->val);
                }
            }
        }
        return ans;
    }
};