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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        ListNode* temp = head;
        ListNode* tail = nullptr;
        int n = 0;
        while(temp){
            tail = temp;
            temp = temp->next;
            n++;
        }
        k=k%n;
        tail->next = head;
        temp = head;
        for(int i=0;i<n-k-1;i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};