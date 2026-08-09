/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode dummy={0,head};
    struct ListNode* prev=&dummy;
    struct ListNode* cur=head;
    

    while(cur){
        bool duplicate=0;
        while(cur->next&&cur->val==cur->next->val){
            duplicate=1;
            cur=cur->next;
        }

        if(duplicate){
            cur=cur->next;

            struct ListNode* rmnode=prev->next;

            while(rmnode!=cur){
                struct ListNode* this=rmnode;
                rmnode=rmnode->next;
                free(this);    
            }

            prev->next=cur;
        }else{
            prev=cur;
            cur=cur->next;
        }
    }

    return dummy.next;
}
