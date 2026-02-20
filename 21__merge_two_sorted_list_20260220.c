
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode s;
    struct ListNode* cur;
    cur=&s;
    s.next=NULL;
    
    while (list1!=NULL && list2!=NULL){
        if (list1->val<list2->val){
            cur->next=list1;
            list1=list1->next;           
        }else{
            cur->next=list2;
            list2=list2->next;
        }
        cur=cur->next;
    }
    
    cur->next=(list1==NULL)?list2:list1;
    return s.next;
}
