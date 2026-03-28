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
    ListNode* reverseNode(ListNode* head, int k){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr && k){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            k--;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp=temp->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevTail = dummy;
        temp = head;
        while(count>=k){
            ListNode* nextHead = temp;
            for(int i=0;i<k;i++){
                nextHead = nextHead->next;
            }
            ListNode* tail = temp;
            ListNode* newHead = reverseNode(temp,k);
            prevTail->next = newHead;
            tail->next = nextHead;
            prevTail = tail;
            temp = nextHead;
            count-=k;
        }
        return dummy->next;
    }
};