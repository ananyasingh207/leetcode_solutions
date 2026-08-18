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

class NodeValue {
public:
    int mn, mx, sum;
    NodeValue(int mn, int mx, int sum) : mn(mn), mx(mx), sum(sum) {}
};

class Solution {
private:
    int maxSum = 0;
    NodeValue helper(TreeNode* root) {
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);
        auto left = helper(root->left);
        auto right = helper(root->right);
        if (root->val > left.mx && root->val < right.mn) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return NodeValue(min(root->val, left.mn), max(root->val, right.mx), currSum);
        }
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        helper(root);
        return maxSum;
    }
};