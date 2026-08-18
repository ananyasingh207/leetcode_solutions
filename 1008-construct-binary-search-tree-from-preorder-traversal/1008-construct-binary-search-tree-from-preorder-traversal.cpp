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
    TreeNode* bst(vector<int>& preorder,int& index,long bound){
        if(index==preorder.size() || preorder[index]>bound){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root->left = bst(preorder,index,root->val);
        root->right = bst(preorder,index,bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bst(preorder,index,LONG_MAX);
    }
};