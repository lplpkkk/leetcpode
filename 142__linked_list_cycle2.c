/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {

    //find the meet point
    if((head==NULL) || (head->next==NULL) || (head->next->next==NULL)){
        return NULL;
    }

    struct ListNode* fast=head->next->next;//1
    struct ListNode* slow=head->next;//1

    while(fast!=slow){
        if((fast->next==NULL)||(fast->next->next==NULL)){
            return NULL;
        }
        if(slow->next==NULL){
            return NULL;
        }

        fast=fast->next->next;
        slow=slow->next;
    }

    slow=head;
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }

    return fast;

}
