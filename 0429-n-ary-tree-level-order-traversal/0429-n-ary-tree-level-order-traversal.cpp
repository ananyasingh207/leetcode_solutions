/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        queue<Node*> eq;
        eq.push(root);
        while(!eq.empty()){
            vector<int> level;
            int n = eq.size();
            for(int i=0;i<n;i++){
                Node* front = eq.front();
                int value = front->val;
                level.push_back(value);
                eq.pop();
                for(auto child : front->children){
                    eq.push(child);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};