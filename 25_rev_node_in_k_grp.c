/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* larger_k(struct ListNode* l, int k){
    
    for(int i=0;i< (k-1);i++){
        if(l==NULL){
            return NULL;
        }
        l=l->next;
    }

    return l;
}

struct ListNode* reverse(struct ListNode* l, int k){
    struct ListNode* prev=NULL;

    for(int i=0;i<k;i++){
        struct ListNode* tmp=l->next;
        l->next=prev;
        prev=l;
        l=tmp;    
    }

    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    struct ListNode dummy={0,NULL};
    struct ListNode* last_group=&dummy;
    struct ListNode* cur=head;
    

    while(cur){
        struct ListNode* kth=larger_k(cur,k);

        if(kth==NULL){
            break;
        }

        //link last group
        struct ListNode* next_group=kth->next;

        struct ListNode* new_head=reverse(cur,k);

        last_group->next=new_head;
        cur->next=next_group;

        //move to next group
        last_group=cur;
        cur=next_group;
       
    }

    return dummy.next;
}
