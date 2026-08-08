struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* newhead = head->next;
    free(head);

    struct ListNode* read = newhead;
    struct ListNode* write = newhead;
    struct ListNode* lastwritten = NULL;

    int sum = 0;

    while (read != NULL) {
        if(read->val!=0){
            sum+=read->val;
        }else{
            write->val=sum;
            if(lastwritten!=NULL){
                lastwritten->next=write;
            }
            lastwritten=write;

            sum=0;

            write=read->next;
        }

        read=read->next;
    }

    lastwritten->next=NULL;

    return newhead;
}
