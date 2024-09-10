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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL || head==NULL)
        return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while( fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                prev=slow;
                slow=slow->next;
            }
        }
        prev->next=slow->next;
        delete slow;
        return head;
    }
};