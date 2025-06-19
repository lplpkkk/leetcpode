/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if(!node || node->next==NULL){
        return;
    }

    struct ListNode * tmp=node->next;
    node->val=tmp->val;
    node->next=tmp->next;
    free(tmp);

    return;
}
