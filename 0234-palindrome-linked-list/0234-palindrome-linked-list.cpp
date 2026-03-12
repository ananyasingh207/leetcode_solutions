/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr){
            return true;
        }
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        temp = head;
        while(temp || !st.empty()){
            ListNode* top = st.top();
            st.pop();
            if(top->val!=temp->val){
                return false;
            }
            temp=temp->next;
        }
        return true;
    }
};