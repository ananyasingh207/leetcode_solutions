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

    void solve(TreeNode* root, int targetSum, long long sum, unordered_map<long long, int>& prefix, int& paths){
        if(root==nullptr) return;
        sum+=root->val;
        if(prefix.count(sum-targetSum)){
            paths+=prefix[sum-targetSum];
        }
        prefix[sum]++;
        solve(root->left,targetSum,sum,prefix,paths);
        solve(root->right,targetSum,sum,prefix,paths);
        prefix[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0]=1;
        int path = 0;
        solve(root,targetSum,0,prefix,path);
        return path;
    }
};