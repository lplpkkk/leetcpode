/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#if(0)
struct ListNode* find_mid(struct ListNode* head){
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    struct ListNode* ans;

    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ans=slow->next;
    slow->next=NULL;

    return ans;
} 
#endif
struct ListNode* find_mid(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) prev->next = NULL;  // 切斷左半部與右半部

    return slow;  // right half 開頭
}


struct ListNode* merge(struct ListNode* a, struct ListNode*b){
    struct ListNode dummy;
    struct ListNode* tail = &dummy;

    while(a && b){
        if(a->val < b->val){
            tail->next=a;
            a=a->next;
        }else{
            tail->next=b;
            b=b->next;
        }
        tail=tail->next;
    }

    if(a){
        tail->next=a;
    }else{
        tail->next=b;
    }

    return dummy.next;


} 

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;
    
    struct ListNode* mid=find_mid(head);

    struct ListNode* l=head;
    struct ListNode* r=mid;

    l=sortList(l);
    r=sortList(r);

    l=merge(l,r);

    return l;
}
