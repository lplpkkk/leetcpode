class Skiplist {
private:

    static const int layer=16;

    struct ListNode{
        int val;
        ListNode* next[layer];

        ListNode(int v): val(v) {
            for(int i=0;i<layer;i++){
                next[i]=nullptr;
            }
        } 
    };

    ListNode* head;

public:
    Skiplist() {
        head=new ListNode(-1);            
    }
    
    bool search(int target) {
        
        struct ListNode* cur=head;

        for(int i=layer-1;i>=0;i--){
            while(cur->next[i]&&cur->next[i]->val<target){
                cur=cur->next[i];
            }          
        }        

        cur=cur->next[0];

        return cur&&cur->val==target;
    }
    
    void add(int num) {
        struct ListNode* cur=head;
        struct ListNode* update[layer];

        for(int i=layer-1;i>=0;i--){
            while(cur->next[i]&&cur->next[i]->val<num){
                cur=cur->next[i];
            }          

            update[i]=cur;
        }

        int lv=1;
        
        while(lv<layer&&random()%2==0){
            lv++;
        }

        ListNode * node=new ListNode(num);

        for(int i=0;i<lv;i++){
            node->next[i]=update[i]->next[i];
            update[i]->next[i]=node;
        }
        return;
    }
    
    bool erase(int num) {
        struct ListNode* cur=head;
        struct ListNode* update[layer];

        for(int i=layer-1;i>=0;i--){
            while(cur->next[i]&&cur->next[i]->val<num){
                cur=cur->next[i];
            }          

            update[i]=cur;
        }

        ListNode* target=update[0]->next[0];

        if(!target||target->val!=num){
            return false;
        }

        //search then erase
        for(int i=0;i<layer;i++){
            if(update[i]->next[i]==target){
                update[i]->next[i]=target->next[i];
            }
        }

        delete target;

        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
