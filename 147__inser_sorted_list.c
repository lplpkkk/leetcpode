/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(!head || !head->next){
        return head;
    }

    struct ListNode* cur=head; 
    struct ListNode dummy={0,NULL};


    while(cur){
        struct ListNode* prev=&dummy;
        struct ListNode* next=cur->next;

        while(prev->next && prev->next->val <cur->val){
            prev=prev->next;
        }

        cur->next=prev->next;
        prev->next=cur;
        cur=next;
    }

    return dummy.next;
    
}
