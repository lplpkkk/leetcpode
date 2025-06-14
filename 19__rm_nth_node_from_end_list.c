/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #define MAX_BUF 30
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
        void* buf[MAX_BUF];
        int cur_buf_idx=0;
        struct ListNode* cur=head;

        while(cur){
            buf[cur_buf_idx++]=cur;
            cur=cur->next;
        }

        // here is t end, end_idx=cur_buf_idx
        // remove node_idx=(cur_buf_idx-n)       
        int rm_node_idx=(cur_buf_idx-n);
        int prev_rm_node_idx=(cur_buf_idx-n-1);

        if(prev_rm_node_idx>=0){
            ((struct ListNode*)buf[prev_rm_node_idx])->next=
            ((struct ListNode*)buf[rm_node_idx])->next;
            free(buf[rm_node_idx]);
        }else{
            //remove the head
            cur=head;
            head=head->next;
            free(cur);
        }
        
        return head;
}
