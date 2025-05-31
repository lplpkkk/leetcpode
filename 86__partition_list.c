/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//5/31 11:43

// 1st (<x)
// 2nd (>=x)

// 1->4->3, 2->5->2
// 1->4->3, 2->5->2

// while(list->val==x)
//      if(!p1_start)
//        p1_start = (list->val<x)
//      nodex=get the end the 1st

// while(noedex->next)
//      insert_front(p1_start,nodex)
//      nodex=nodex->nexx


#if(0)

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* p1_start=NULL;
    struct ListNode* cur=head;
    struct ListNode* nodex=NULL;
    struct ListNode* tmp=NULL;

    // track all nodes
    while(cur){

        if(!p1_start){
            if(cur->val<x){
                p1_start=cur;    
            }
        }

        if(cur->val==x){
            nodex=cur;
        }

        cur=cur->next;
    }

    cur=nodex;
    if(!p1_start){
        p1_start=nodex;
    }


    while(cur){

        if(cur->val<x){
            tmp=p1_start->next;

            p1_start->next=cur;
            cur->next=tmp;
            p1_start=p1_start->next;
        }

        cur=cur->next;
    }

    return head;
}
#endif

// use classic way to do that, 5/31 12:24
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode before_node={0,NULL};
    struct ListNode after_node={0,NULL};
    
    struct ListNode* before=&before_node;
    struct ListNode* after=&after_node;

    while(head){
        if(head->val<x){
            before->next=head;
            before=before->next;    
        }else{
            after->next=head;
            after=after->next;
        }

        head=head->next;
    }

    before->next=after_node.next;
    after->next=NULL;

    return before_node.next;
}
