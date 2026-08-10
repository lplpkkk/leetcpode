/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode dummy={0,head->next};
    struct ListNode* prev=head->next;
    struct ListNode* cur=head->next;
    int sum=0;

    while(cur){
        if(cur->val!=0){
            sum+=cur->val;
        }else{
            //update 1st non-0
            prev->val=sum;
            //1st non-0 point to '0' node
            prev->next=cur->next;

            sum=0;
            
            prev=cur->next;
        }

        cur=cur->next;
    }

    return dummy.next;    
}
