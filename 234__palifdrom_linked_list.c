/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* rev=NULL;
    struct ListNode* cur=head;
    struct ListNode* prev=NULL;

    while(cur){
        struct ListNode* tmp=malloc(sizeof(struct ListNode));
        tmp->val=cur->val;
        tmp->next=rev;
        rev=tmp;

        cur=cur->next;
    }

    cur=head;
    struct ListNode* p=rev;

    while(cur && p ){
        if(cur->val!=p->val){
            while(rev){
                struct ListNode* k=rev;
                rev=rev->next;
                free(k);
            }

            return false;
        }
        cur=cur->next;
        p=p->next;    
    }

    while(rev){
        struct ListNode* k=rev;
        rev=rev->next;
        free(k);
    }

    return true;

}
