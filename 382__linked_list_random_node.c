/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



typedef struct {
    struct ListNode *head;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution *obj=malloc(sizeof(Solution));
    
    //obj->head=malloc(sizeof(struct ListNode));
    //obj->head->next=NULL;
    obj->head=head;
    srand(time(NULL));
    return obj;
}

#if(1)
int solutionGetRandom(Solution* obj) {
    int len=0;
    struct ListNode *cur=obj->head;

    if(!cur){
        return -1;
    }

    //printf(" [before loop] cur=%p \n",cur);
    //printf(" [before loop] cur=%p , cur->next=%p\n",cur,cur->next);
    while(cur){
        len++;
        cur=cur->next;
    }

    int sel=rand()%len;
    cur=obj->head;

    for(int i=0;i<sel;i++){
        cur=cur->next;
    }
    return cur->val;
}
#else
int solutionGetRandom(Solution* obj) {
    struct ListNode *cur = obj->head;
    if (!cur) return -1;  // 或根据题意返回 0 此类的 fallback

    int len = 0;
    while (cur) { len++; cur = cur->next; }

    int sel = rand() % len;  // 至此 sel 在 [0, len-1] 范围内
    cur = obj->head;
    while (sel--) {
        cur = cur->next;
    }
    return cur->val;  // 此时 cur 一定为有效节点
}
#endif

void solutionFree(Solution* obj) {
    struct ListNode* cur=obj->head;

    while(cur){
        struct ListNode* tmp=cur->next;
        free(cur);
        cur=tmp;
    }

    free(obj);
    return;
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
