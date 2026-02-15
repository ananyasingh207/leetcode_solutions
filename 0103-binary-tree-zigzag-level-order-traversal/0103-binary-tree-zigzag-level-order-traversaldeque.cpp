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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> eq;
        eq.push(root);
        bool leftToRight = true;
        while(!eq.empty()){
            int n = eq.size();
            vector<int> level(n);
            for(int i=0;i<n;i++){
                TreeNode* front = eq.front();
                eq.pop();
                int index = leftToRight ? i : n - 1 - i; 
                level[index] = front->val;
                if(front->left) eq.push(front->left); 
                if(front->right) eq.push(front->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
    }
};