/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge_list(struct ListNode* l1, struct ListNode* l2){
    struct ListNode dummy={0,NULL};
    struct ListNode* tail=&dummy;

    while(l1 && l2){
        if( l1->val < l2->val){
            tail->next=l1;
            l1=l1->next;
        }else{
            tail->next=l2;
            l2=l2->next;
        }

        tail=tail->next;
    }
    
    tail->next=(l1)?l1:l2;

    return dummy.next;

}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    //split into 2part, 0~n, (n+1)~list_size
    //while(list>1) 1.split, merge
    if (listsSize == 0) return NULL;
    
    while(listsSize>1){
        int n=(listsSize+1)/2;    

        for(int i=0;i< listsSize/2;i++){          
            lists[i]=merge_list(lists[i],lists[i+n]);
        }

        listsSize=n;    
    }

    return lists[0];
}
