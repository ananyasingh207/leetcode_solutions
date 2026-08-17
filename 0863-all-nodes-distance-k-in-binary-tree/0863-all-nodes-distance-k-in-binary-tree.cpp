/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left){
                    parent[front->left]=front;
                    q.push(front->left);
                }
                if(front->right){
                    parent[front->right]=front;
                    q.push(front->right);
                }
            }
        }
        vector<int> ans;
        queue<pair<TreeNode*,int>> q2;
        unordered_map<TreeNode*,bool> vis;
        q2.push({target,0});
        vis[target]=true;
        while(!q2.empty()){
            int n = q2.size();
            for(int i=0;i<n;i++){
                auto front = q2.front();
                TreeNode* node = front.first;
                int dist = front.second;
                if(dist==k) ans.push_back(node->val);
                q2.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left] = true;
                    q2.push({node->left,dist+1});
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q2.push({node->right,dist+1});
                }
                if(parent.find(node)!=parent.end() && !vis[parent[node]]){
                    vis[parent[node]] = true;
                    q2.push({parent[node],dist+1});
                }
            }
        }
        return ans;
    }
};