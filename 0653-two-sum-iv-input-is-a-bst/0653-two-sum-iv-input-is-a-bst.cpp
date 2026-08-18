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
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse; // false -> normal inorder (next), true -> reverse inorder (before)

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }

    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        if (reverse) pushAll(topNode->left);
        else pushAll(topNode->right);
        return topNode->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr) return false;
        BSTIterator leftIt(root,false);
        BSTIterator rightIt(root,true);
        int l = leftIt.next();
        int r = rightIt.next();
        while(l<r){
            int sum = l+r;
            if(sum==k) return true;
            if(sum<k){
                l = leftIt.next();
            }
            else{
                r = rightIt.next();
            }
        }
        return false;
    }
};