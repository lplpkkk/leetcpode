/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head||!head->next||k==0){
        return head;
    }

    //make it a ring

    struct ListNode* cur=head;
    int len=1;

    while(cur->next){
        cur=cur->next;
        len++;
    }

    k%=len;
    if(k==0){
        return head;
    }

    cur->next=head;


    
    int steps=len-k-1;
    struct ListNode* newtail=head;

    for(int i=0;i<steps;i++){
        newtail=newtail->next;
    }

    struct ListNode* ans=newtail->next;
    newtail->next=NULL;


    return ans;

    
}
