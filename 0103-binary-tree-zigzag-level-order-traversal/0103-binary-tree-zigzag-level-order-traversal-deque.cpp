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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> eq;
        eq.push(root);
        bool leftToRight = true;
        while(!eq.empty()){
            int n = eq.size();
            deque<int> level;
            for(int i=0;i<n;i++){
                TreeNode* front = eq.front();
                eq.pop();
                if(leftToRight){
                    level.push_back(front->val);
                }
                else{
                    level.push_front(front->val);
                }
                if(front->left) eq.push(front->left); 
                if(front->right) eq.push(front->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(vector<int>(level.begin(),level.end()));
        }
        return ans;
    }
};