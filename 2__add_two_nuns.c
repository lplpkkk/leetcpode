struct ListNode* insert(struct ListNode* head, struct ListNode* newNode) {
    if (head == NULL) {
        return newNode;
    }

    struct ListNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->next = NULL;
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int l1v = 0, l2v = 0, sum = 0;
    struct ListNode* ans = NULL;

    while (l1 || l2 || carry) {
        l1v = (l1) ? l1->val : 0;
        l2v = (l2) ? l2->val : 0;
        sum = l1v + l2v + carry;
        carry = sum / 10;

        struct ListNode* tmp = malloc(sizeof(struct ListNode));
        tmp->val = sum % 10;
        tmp->next = NULL;

        ans = insert(ans, tmp);  // 返回新 head（如果第一次插入）

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return ans;
}
