/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry=0;
    struct ListNode dummy={0,NULL};
    struct ListNode* tail=malloc(sizeof(struct ListNode));
    tail=&dummy;

    while(l1!=NULL|l2!=NULL|carry){
        int sum=carry;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }

        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }

        struct ListNode* new_node=malloc(sizeof(struct ListNode));
        new_node->val=sum%10;
        new_node->next=NULL;
        carry=sum/10;

        tail->next=new_node;
        tail=tail->next;
    }

    return dummy.next;
}
