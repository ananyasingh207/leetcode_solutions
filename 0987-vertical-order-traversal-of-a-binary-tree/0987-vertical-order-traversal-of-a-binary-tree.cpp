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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto front = q.front();
            TreeNode* node = front.first;
            int hd = front.second.first;
            int level = front.second.second;
            nodes[hd][level].push_back(node->val); 
            q.pop();
            if(node->left) q.push({node->left,{hd-1,level+1}});
            if(node->right) q.push({node->right,{hd+1,level+1}});
        }
        vector<vector<int>> ans;
        for(auto row : nodes){
            vector<int> temp;
            for(auto col : row.second){
                sort(col.second.begin(),col.second.end());
                for(int val : col.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};