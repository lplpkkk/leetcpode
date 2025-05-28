/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#if(1)
void reverse(struct ListNode** l, struct ListNode** r){
    struct ListNode* cur=*l;
    struct ListNode* prev=NULL;
    struct ListNode* tmp=NULL;
    struct ListNode* end=(*r)->next;

    while(cur!=end){
        tmp=cur->next;           
        cur->next=prev;
        prev=cur;
        cur=tmp;
    }
    
    struct ListNode* tmp2=*l;
    *r=tmp2;
    *l=prev;

    return;
}


void dump(struct ListNode* l){
    while(l){
        printf(" 0x%x --> ",l->val);
        l=l->next;
    }
    printf("\n");

    return;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    //for loop to the end
    //  get l, record(l-1)
    //  get r, record (r)
    //      get r+1, aka r->next

    //  reverse(**l, **r)
    //          |    |
    //          r    l
    //  (l-1)->next=r
    //  r->next=(r+1)
    
    if((head==NULL) || (head->next)==NULL){
        return head;
    }

    int i=0;
    struct ListNode* cur=head;
    struct ListNode* l1=NULL;
    struct ListNode* l2=NULL;
    struct ListNode* r1=NULL;
    struct ListNode* r2=NULL;

    // l1->{l2...r2}..r1
    for(i=1;i<=right;i++){

        if(i== (left-1)){
            l1=cur;
        }
        
        if((i==left)){
            l2=cur;
        }

        if(i==right){
            r1=cur->next;
            r2=cur;
        }

        cur=cur->next;    
    }

    //r2=cur;
    //r1=cur->next;

    reverse(&l2,&r2);

    #if(1)
    printf("from r2: \n");
    dump(r2);
    printf("from l2: \n");
    dump(l2);
    #endif

    if(l1){
        l1->next=l2;
    }else{
        // handle only one node
        head=l2;       
    }
    
    r2->next=r1;

    return head;
}
#else


void reverse(struct ListNode** start, struct ListNode** end) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = *start;
    struct ListNode* next = NULL;
    struct ListNode* stop = (*end)->next;  // 反轉區間終點的下一個節點

    while (cur != stop) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    // 更新 start 和 end 指標
    // 原本 start 節點變成區間尾，prev 是新的區間頭
    *end = *start;
    *start = prev;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) {
        return head;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    // 移動 prev 到 left 節點的前一個
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    struct ListNode* start = prev->next;  // left 節點
    struct ListNode* end = start;

    // 移動 end 到 right 節點
    for (int i = left; i < right; i++) {
        end = end->next;
    }

    struct ListNode* next = end->next;    // right 節點的下一個

    // 反轉區間 [start, end]
    reverse(&start, &end);

    // 連接前後鏈結
    prev->next = start;
    end->next = next;

    return dummy.next;
}

#endif
