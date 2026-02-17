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

    int lheight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int h  = 0;
        while(root=nullptr){
            h++;
            root=root->left;
        }
        return h;
    }

    int rheight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int h  = 0;
        while(root!=nullptr){
            h++;
            root=root->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int leftHeight = lheight(root);
        int rightHeight = rheight(root);
        if(leftHeight==rightHeight){
            return pow(2,leftHeight)-1;
        }
        else{
            int left = countNodes(root->left);
            int right = countNodes(root->right);
            return 1+left+right;
        }
    }
};