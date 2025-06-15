/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    //split into two
    struct ListNode* slow=head;
    struct ListNode* fast=head;    

    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    // now 'slow->next' is the mid point
    // revert 2nd part
    struct ListNode* cur=slow->next;
    struct ListNode* prev=NULL;

    while(cur){
        struct ListNode* tmp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=tmp;
    }
    slow->next=NULL;

    struct ListNode* first=head;
    struct ListNode* second=prev;

    while(second){
        // first list tmp node
        struct ListNode* tmp1=first->next;
        // second list tmp node
        struct ListNode* tmp2=second->next;

        first->next=second;
        second->next=tmp1;

        first=tmp1;
        second=tmp2;
    }

    return;
}
