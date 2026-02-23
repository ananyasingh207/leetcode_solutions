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

    unordered_map<int, int> map;
    int index = 1;
    void traverse(TreeNode* root){
        if(root==nullptr){
            return;
        }
        traverse(root->left);
        map.insert({index,root->val});
        index++;
        traverse(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        return map[k];
    }
};