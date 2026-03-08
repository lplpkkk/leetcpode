/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    int len=0;
    struct ListNode* tmp=head;

    while(tmp){
        len+=1;
        tmp=tmp->next;
    }

    if(len<=1){
        return NULL;
    }

    int mid=len/2;
    tmp=head;
    
    for(int i=0;i<mid-1;i++){
        tmp=tmp->next;
    }
    
    tmp->next=tmp->next->next;

    return head;
    
}
