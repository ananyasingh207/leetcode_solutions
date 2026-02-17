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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxCount = 0;
        if(root==nullptr){
            return (int)maxCount;
        }
        queue<pair<TreeNode*,long long>> eq;
        eq.push({root,0});
        while(!eq.empty()){
            int n = eq.size();
            long long first = eq.front().second;
            long long last = eq.back().second;
            maxCount = max(maxCount,last-first+1);
            for(int i=0;i<n;i++){
                auto front = eq.front();
                TreeNode* node = front.first;
                long long index = front.second - first;
                eq.pop();
                if(node->left) eq.push({node->left,2*index});
                if(node->right) eq.push({node->right,2*index+1});
            }
        }
        return (int)maxCount;
    }
};