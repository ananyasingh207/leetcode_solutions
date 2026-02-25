/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr){
            return root;
        }
        queue<Node*> eq;
        eq.push(root);
        while(!eq.empty()){
            int n = eq.size();
            Node* prev = nullptr;
            for(int i=0;i<n;i++){
                Node* front = eq.front();
                eq.pop();
                if(prev){
                    prev->next = front;
                }
                prev = front;
                if(front->left){
                    eq.push(front->left);
                }
                if(front->right){
                    eq.push(front->right);
                }
            }
        }
        return root;
    }
};