class MyLinkedList {
private:
    struct ListNode{
        int val;
        ListNode* next;
        
        ListNode(int v): val(v), next(nullptr){};
    };

    ListNode* head;

public:
    MyLinkedList() {
        head=nullptr;
    }
    
    int get(int index) {
        ListNode* cur=head;

        while(index){
            if(cur==NULL){
                return -1;
            }
            cur=cur->next;
            index--;
        }    

        if(cur==nullptr){
            return -1;
        }

        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newnode=new ListNode(val);
        newnode->next=head;
        head=newnode;
    }
    
    void addAtTail(int val) {
        ListNode* cur=head;

        if(cur==nullptr){
            head=new ListNode(val);
            return;
        }

        while(cur->next){
            cur=cur->next;    
        }
        
        cur->next=new ListNode(val);
    }
    
    void addAtIndex(int index, int val) {
        ListNode* cur=head;
        ListNode* prev=head;

        if(index==0){
            addAtHead(val);
            return;
        }

        while(index){
            if(cur==nullptr){
                return;
            }

            index--;

            prev=cur;
            cur=cur->next;
            
        }

        prev->next=new ListNode(val);
        prev->next->next=cur;
    }
    
    void deleteAtIndex(int index) {
        ListNode* cur=head;
        ListNode* prev=head;

        if(index==0){
            if(head==nullptr){
                return;
            }

            ListNode* tbd=head;
            head=head->next;
            delete tbd;

            return;
        }

        while(index){
            if(cur==nullptr){
                return;
            }

            index--;

            prev=cur;
            cur=cur->next;
        }

        if(cur==nullptr){
            return;
        }

        ListNode* tbd=cur;
        prev->next=cur->next;
        delete tbd;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
