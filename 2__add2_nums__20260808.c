/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy=malloc(sizeof(struct ListNode));
    struct ListNode* tail = dummy;

    int carry=0;

    while(l1||l2||carry){
        int digit1=(l1)?l1->val:0;
        int digit2=(l2)?l2->val:0;

        int sum=(digit1+digit2+carry);
        int digit=sum%10;
        carry=sum/10;

        struct ListNode* newnode=malloc(sizeof(struct ListNode));
        newnode->val=digit;
        newnode->next=NULL;
        tail->next=newnode;
        tail=tail->next;

        l1=(l1)?l1->next:NULL;
        l2=(l2)?l2->next:NULL;
    }

    struct ListNode* ans=dummy->next;
    free(dummy);
    return ans;
    
}
