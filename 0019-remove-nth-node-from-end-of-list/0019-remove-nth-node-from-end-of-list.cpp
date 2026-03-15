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
    int getSize(ListNode* head){
        if(head==nullptr){
            return 0;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = getSize(head);
        if(k == n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* temp = head;
        for(int i=1;i<k-n;i++){
            temp = temp->next;
        }
        ListNode* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        return head;
    }
};