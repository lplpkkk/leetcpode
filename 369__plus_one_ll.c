
struct ListNode* plusOne(struct ListNode* head) {
    struct ListNode dummy = {0, head};

    struct ListNode* cur=&dummy;
    struct ListNode* last_non9=&dummy;

    while(cur){
    	if(cur->val!=9){
    		last_non9=cur;
    	}
    	cur=cur->next;
    }

    last_non9->val++;

    cur=last_non9->next;

    while(cur){
    	
    	cur->val=0;
    	
    	cur=cur->next;
    }

    if(dummy.val==1){
    	struct ListNode* newnode=malloc(sizeof(struct ListNode));
  		newnode->val=1;
  		newnode->next=head;
  		dummy.next=newnode;
    }

    return dummy.next;
}



