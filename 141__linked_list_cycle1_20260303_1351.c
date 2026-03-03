/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL){
        return false;
    }
    struct ListNode* slow=head;//1->2->1
    struct ListNode* fast=head;//1->1->1

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow){
            return true;
        }
    }

    return false;
    
}
