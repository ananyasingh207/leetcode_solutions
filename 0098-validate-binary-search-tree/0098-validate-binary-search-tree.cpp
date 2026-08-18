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
    bool validateBST(TreeNode* root, long long mx, long long mn){
        if(root==nullptr) return true;
        if(root->val<=mn || root->val>=mx) return false;
        bool left = validateBST(root->left,root->val,mn);
        bool right = validateBST(root->right,mx,root->val);
        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return validateBST(root,LLONG_MAX,LLONG_MIN);
    }
};