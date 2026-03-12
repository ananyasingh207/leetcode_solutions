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
    ListNode* reverse(ListNode* head){
        if(head==nullptr){
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow->next);
        ListNode* temp1 = head;
        ListNode* temp2 = rev;
        while(temp1!=slow->next && temp2){
            if(temp1->val!=temp2->val){
                reverse(rev);
                return false;
            }
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        reverse(rev);
        return true;
    }
};