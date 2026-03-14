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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int i = 0;
        temp = head;
        while(temp && i<arr.size()){
            if(i%2==0){
                temp->val = arr[i];
                temp=temp->next;
            }
            i++;
        }
        i = 0;
        while(temp && i<arr.size()){
            if(i%2==1){
                temp->val = arr[i];
                temp=temp->next;
            }
            i++;
        }
        return head;
    }
};