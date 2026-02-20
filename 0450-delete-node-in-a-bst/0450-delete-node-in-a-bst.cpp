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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return root;
        }
        if(root->val==key){
            if(root->left==nullptr && root->right==nullptr){
                delete(root);
                return nullptr;
            }
            else if(root->left!=nullptr && root->right==nullptr){
                TreeNode* temp = root;
                root=root->left;
                delete(temp);
            }
            else if(root->left==nullptr && root->right!=nullptr){
                TreeNode* temp = root;
                root=root->right;
                delete(temp);
            }
            else if(root->left!=nullptr && root->right!=nullptr){
                //Inorder Successor = The smallest value in right subtree
                TreeNode* inorderSuccessor = root->right;
                while(inorderSuccessor->left!=nullptr){
                    inorderSuccessor=inorderSuccessor->left;
                }
                root->val = inorderSuccessor->val;
                root->right = deleteNode(root->right,inorderSuccessor->val);
            }
        }
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }

        else if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        return root;
    }
};