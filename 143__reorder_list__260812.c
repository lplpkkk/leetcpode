/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode* fast=head;
    struct ListNode* slow=head;

    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }

    if(fast==slow){
        return ;
    }

    //reverse the 2nd one
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
        struct ListNode* tmp1=first->next;
        struct ListNode* tmp2=second->next;

        
        first->next=second;
        second->next=tmp1;

        first=tmp1;
        second=tmp2;
    }

    return;
}
