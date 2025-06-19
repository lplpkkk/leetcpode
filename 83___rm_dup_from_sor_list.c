/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head){
        return NULL;
    }else if(head->next==NULL){
        return head;
    }

    struct ListNode* cur=head->next;
    struct ListNode* prev=head;
    int dup_val=head->val;

    while(cur){
        if(cur->val==dup_val){
            prev->next=cur->next;
            struct ListNode* tmp=cur;
            cur=cur->next;
            free(tmp);
        }else{
            prev=cur;    
            cur=cur->next;
        }
        dup_val=prev->val;
    }

    return head;
}
