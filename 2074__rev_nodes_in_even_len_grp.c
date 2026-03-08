/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* list, int len){
    struct ListNode* cur=list;
    struct ListNode* prev=NULL;

    for(int i=0;i<len;i++){
        struct ListNode* tmp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=tmp;
    }
    list->next=cur;
    return prev;
}


struct ListNode* reverseEvenLengthGroups(struct ListNode* head) {
    struct ListNode* prev_grp_tail=head;
    int grp_size=2;

    while(prev_grp_tail->next){
        struct ListNode* cur=prev_grp_tail->next;
        int actual_len=0;
        struct ListNode* tmp=cur;

        while(tmp&&actual_len<grp_size){
            actual_len++;
            tmp=tmp->next;
        }

        if((actual_len&1)==0){
            prev_grp_tail->next=reverse(cur,actual_len);
            prev_grp_tail=cur;
        }else{
            for(int i=0;i<actual_len;i++){
                prev_grp_tail=prev_grp_tail->next;
            }
        }

        grp_size++;
    }
    return head;
}
