/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode dummy={0,head};
    struct ListNode* tail=head;
    struct ListNode* prev=&dummy;
    //tail->next=head;

    while(tail){
        if(tail->val==val){
            struct ListNode* tmp=tail->next;
            prev->next=tmp;
            struct ListNode* freenode=tail;
            tail=tmp;
            free(freenode);
        }else{
            prev=tail;
            tail=tail->next;
        }
    }
    
    return dummy.next;
}
