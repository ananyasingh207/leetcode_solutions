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
    int mn = INT_MAX;
    TreeNode* prev = nullptr;

    void traverse(TreeNode* root){
        if(root==nullptr){
            return;
        }
        traverse(root->left);
        if(prev!=nullptr){
            mn = min(root->val-prev->val, mn);
        }
        prev = root;
        traverse(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        traverse(root);
        return mn;
    }
};