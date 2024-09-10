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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode *current,*prev;
    current=head;
    prev=NULL;
    while(current!=NULL){
        if(current->next!=NULL && current->val == current->next->val){
            while(current->next!=NULL && current->val == current->next->val){
            current=current->next;
            }
            if(prev==NULL){
                head=current->next;
            }
            else{
            prev->next=current->next;}
        }
        else{
            prev=current;
        }
            current=current->next;
    }
    return head;
    }
};