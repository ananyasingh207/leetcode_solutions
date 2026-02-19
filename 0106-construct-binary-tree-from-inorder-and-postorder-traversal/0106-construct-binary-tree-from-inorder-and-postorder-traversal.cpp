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

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int& index,int left, int right){
        if(left>right){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[index]);
        int inIdx = map[postorder[index]];
        index--;
        root->right = helper(inorder,postorder,index,inIdx+1,right);
        root->left = helper(inorder,postorder,index,left,inIdx-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        int index = inorder.size()-1;
        return helper(inorder,postorder,index,0,inorder.size()-1);
    }
};