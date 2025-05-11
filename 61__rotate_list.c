/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#if(0)
int find_len(struct ListNode* h){
    int len=0;
    while(h->next!=NULL){
        len++;
        h=h->next;
    }
    return len;
}

struct ListNode* get_node(struct ListNode* h, int step){

    
    for(int i=0;i<step;i++){
        if(h->next!=NULL){
            h=h->next;
        }else{
            return NULL;
        }    
    }

    return h;
}

 // 22:19, May 7th
struct ListNode* rotateRight(struct ListNode* head, int k) {

    int len=find_len(head);
    
    if(len==0){return NULL;}

    //at least one node here

    int step=k%len;
    
    struct ListNode* top_end;
    struct ListNode* new_top_top;
    // 1->2->3->4->5
    // |___    
    top_end=get_node(head,step);
    new_top_top=get_node(head,step+1);

    //single node case
    if( (top_end==NULL) || (new_top_top==NULL) ){
        return head;
    }

    // 1->2, 3->4->5
    while(top_end->next!=NULL){
        top_end=top_end->next;
    }
    
    top_end->next=NULL;
    // 1->2, 3->4->5
    // |___________
    new_top_top->next = head;

    return new_top_top;
}
#else


struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* p=head;
    int len=1;

    // make it a ring
    if(head==NULL){
        return NULL;
    }else if(head->next==NULL){
        return head;
    }
    
    while(p->next!=NULL){
        p=p->next;
        len++;
    }

    ///printf("len is %d\n",len);

    //.    _____len__
    //.    |         |
    //  p->h--
    p->next=head;
    
    int step=(k%len);
    //.    _____len__
    //.    |         |
    //     h         p
    //         p
    //     k.  p
    //     p

    // go back to the 'old' first and track to the 'new' last
    p=head;

    for(int i=0;i<(len-step-1);i++){
        p=p->next;
        //printf("i:%d, p->val=%d\n",i,p->val);
    }

    struct ListNode* ans=p;
    ans=p->next;
    p->next=NULL;

    return ans;
    
    

    
}
#endif
