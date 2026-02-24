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
    TreeNode* bst(vector<int>& preorder,int& index,long mn, long mx){
        if(preorder.size()==0){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        if(index==preorder.size()-1){
            return root;
        }
        index++;
        if(preorder[index]<root->val && preorder[index]>mn && preorder[index]<mx){
            root->left = bst(preorder,index,mn,root->val);
        }
        if(preorder[index]>root->val && preorder[index]>mn && preorder[index]<mx){
            root->right = bst(preorder,index,root->val,mx);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bst(preorder,index,LONG_MIN,LONG_MAX);
    }
};