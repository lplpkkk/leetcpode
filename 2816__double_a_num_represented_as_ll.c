/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev=NULL;
    struct ListNode* cur=head;

    while(cur!=NULL){
        struct ListNode* next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }

    return prev;
}

struct ListNode* doubleIt(struct ListNode* head) {
    head=reverse(head);

    struct ListNode* cur=head;
    struct ListNode* last=NULL;//?
    
    int carry=0;
    while(cur!=NULL){
        int val=cur->val*2+carry;
        
        cur->val=val%10;
        carry=val/10;

        last=cur;
        cur=cur->next;
    }

    if(carry>0){
        last->next=malloc(sizeof(struct ListNode));
        last->next->val=1;
        last->next->next=NULL;
    }

    return reverse(head);
}
