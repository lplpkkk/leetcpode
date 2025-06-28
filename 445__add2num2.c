/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    char s1[100];
    char s2[100];
    char top1=0;
    char top2=0;

    while(l1){
        s1[top1++]=l1->val;
        l1=l1->next;
    }

    while(l2){
        s2[top2++]=l2->val;
        l2=l2->next;
    }

    char carry=0;
    char sum=0;
    struct ListNode* ans=NULL;

    while(top1>0 || top2>0 || carry){
        char a=(top1>0)? s1[--top1]:0;
        char b=(top2>0)? s2[--top2]:0;
        
        sum=a+b+carry;
        
        carry=sum/10;
        sum=sum%10;
        
        struct ListNode* this_node=malloc(sizeof(struct ListNode));
        this_node->val=sum;
        this_node->next=ans;
        ans=this_node;
    }

    return ans;

}
