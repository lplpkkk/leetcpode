/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* pA=headA;
    struct ListNode* pB=headB;        

    while(pA!=pB){
        pA=(pA!=NULL)?pA->next:headB;
        pB=(pB!=NULL)?pB->next:headA;
    }

    return pA;
}
