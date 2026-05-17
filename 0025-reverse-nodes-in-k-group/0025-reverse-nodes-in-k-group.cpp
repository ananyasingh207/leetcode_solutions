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
    ListNode* rev(ListNode* head, int k){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp && k){
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
            k--;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp = head;
        ListNode* newHead = nullptr;
        ListNode* prevTail = nullptr;
        while(temp){
            ListNode* curr = temp;
            ListNode* tail = temp;
            ListNode* nextHead = temp;
            int b = k;
            while(b && nextHead){
                b--;
                nextHead = nextHead->next;
            }
            if(b>0){
                break;
            }
            ListNode* revHead = rev(curr,k);
            if(temp==head){
                newHead = revHead;
            }
            else{
                prevTail->next = revHead;
            }
            tail->next = nextHead;
            prevTail = tail;
            temp = nextHead;
        }
        return newHead;
    }
};