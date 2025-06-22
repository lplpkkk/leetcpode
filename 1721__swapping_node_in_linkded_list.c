#if(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* cur=head;
    struct ListNode* second=cur;

    for(int i=1;i<k;i++){
        cur=cur->next;
    }
    struct ListNode* first=cur;
    
    while(cur->next){
        cur=cur->next;
        second=second->next;
    }

    int tmp=first->val;
    first->val=second->val;
    second->val=tmp;
    
    return head;   
}
#else
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode *first = head, *second = head, *p = head;
    // 把 p 移到第 k 個節點
    for (int i = 1; i < k; i++) {
        if (p) p = p->next;
    }
    first = p;  // 第 k 個節點

    // 同時移動 p 和 second，直到 p 到末尾
    while (p->next) {
        p = p->next;
        second = second->next;
    }

    // 此時 second 指向倒數第 k 個節點，進行值交換
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;

    return head;
}

#endif
