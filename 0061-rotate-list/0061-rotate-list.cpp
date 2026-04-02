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
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* last = nullptr;
        ListNode* temp = head;
        int n = 0;
        ListNode* prev = nullptr;
        while(temp){
            temp=temp->next;
            n++;
        }
        temp=head;
        int count = k%n;
        while(count){
            temp = head;
            while(temp->next){
                prev = temp;
                temp = temp->next;
            }
            last = temp;
            last->next = head;
            head = last;
            prev->next = nullptr;
            count--;
        }
        return head;
    }
};