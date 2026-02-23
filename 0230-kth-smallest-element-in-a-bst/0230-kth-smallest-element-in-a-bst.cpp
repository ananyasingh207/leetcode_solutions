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
    void traverse(TreeNode* root, int& index,int& ans,int k){
        if(root==nullptr || index>=k){
            return;
        }
        traverse(root->left,index,ans,k);
        index++;
        if(index==k){
            ans = root->val;
            return;
        }
        traverse(root->right,index,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int index = 0;
        int ans = 0;
        traverse(root,index,ans,k);
        return ans;
    }
};