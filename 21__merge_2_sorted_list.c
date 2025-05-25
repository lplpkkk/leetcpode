/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #if(0)
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* ans=malloc(sizeof(struct ListNode));
    ans->val=0xdeadbeef;
    ans->next=NULL;
    
    //int cur_max=-101;
    struct ListNode* cur=NULL; 

    while(list1 || list2){
        cur= ((list2==NULL)
        ||((list1!=NULL)&&(list1->val<=list2->val))) ?list1:list2;

        if(ans->val==0xdeadbeef){
            ans=cur;
        }else{
            ans->next=cur;
        }
        

        if(cur==list1){
            list1=list1->next;
        }else{
            list2=list2->next;
        }
    }

    return ans;

}
#endif
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* dummy=malloc(sizeof(struct ListNode));
    struct ListNode* tail=dummy;
    // tail 
    // dummy
    // data 

    if((list1==NULL) && (list2==NULL)   ){
        return NULL;
    }


    while(list1 && list2){
        if(list1->val<=list2->val){
            tail->next = list1;
            list1=list1->next;
        }else{
            tail->next=list2;
            list2=list2->next;
        }
        tail=tail->next;
    }   

    // handle left 
    while(list1 || list2){
        if(list1){
            tail->next= list1;
            list1=list1->next;
        }else{
            tail->next = list2;
            list2=list2->next;
        }
        tail=tail->next;
    }

    return dummy->next;
    
}
