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

    unordered_map<int,int> map;

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& idx, int left, int right){
        if(left>right){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[idx]);
        int inIdx = map[preorder[idx]];
        idx++;
        root->left = helper(preorder,inorder,idx,left,inIdx-1);
        root->right = helper(preorder,inorder,idx,inIdx+1,right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
        int idx = 0;
        return helper(preorder,inorder,idx,0,inorder.size()-1);
    }
};