/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/* 

    4 -> 2 -> 1 -> 3
        c
        p
*/


struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode dummy={0,NULL};
    struct ListNode* cur=head;
    
    while(cur){
        struct ListNode* after=cur->next;
        struct ListNode* prev=&dummy;
        
        while(prev->next&& cur->val > prev->next->val){
            prev=prev->next;
        }

        //insert cur after prev
        cur->next=prev->next;
        prev->next=cur;

        cur=after;
    }

    return dummy.next;
    
}
