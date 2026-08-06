/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode dummy={0,list1};
    struct ListNode* prev=&dummy;
    
    for(int i=0;i<a;i++){
        prev=prev->next;
    }

    struct ListNode* after=prev->next;
    for(int i=a;i<=b;i++){
        after=after->next;
    }
    
    prev->next=list2;
    
    struct ListNode* tail=list2;
    while(tail->next!=NULL){
        tail=tail->next;
    }

    tail->next=after;

    return dummy.next;
}
