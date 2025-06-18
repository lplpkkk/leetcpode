/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head){
        return head;
    }
    struct ListNode* cur=head;
    struct ListNode* prev=NULL;

    while(cur){
        struct ListNode* tmp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=tmp;
    }

    return prev;
    
}
