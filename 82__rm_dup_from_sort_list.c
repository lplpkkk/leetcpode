/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#if(0)
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* tmp=head;
    struct ListNode* prev=head;;
    int same_val=0;
    int first_val;
    int kill_first=0;

    if(!head){
        return NULL;
    }else{
        first_val=head->val;
    }
    
    #if(1)
    if((tmp->next)&&(prev->val)==(tmp->next->val)){
        kill_first=1;
    }
    #endif

    while(tmp){
        
        if ((tmp->next)&&(tmp->val!=tmp->next->val)){
            if(same_val){
                // link from prev to this
                prev->next=tmp->next;
                same_val=0;               
                //prev=tmp->next;
            }else{
                prev=tmp;
            }
            
        }else{
            same_val=1;
        }

        tmp=tmp->next;    
    }

    

    if(kill_first){
        head=head->next;
    }

    return head;
}
#endif

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return NULL;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr) {
        bool duplicate = false;
        // 檢查是否有重複值
        while (curr->next && curr->val == curr->next->val) {
            duplicate = true;
            struct ListNode* temp = curr;
            curr = curr->next;
            //free(temp);  // 釋放記憶體，依需要可加上
        }

        if (duplicate) {
            struct ListNode* temp = curr;
            curr = curr->next;
            //free(temp);  // 移除最後一個重複節點
            prev->next = curr;  // 跳過整個重複區段
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}
