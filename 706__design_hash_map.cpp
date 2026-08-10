class MyHashMap {
private:
    struct ListNode{
        int key;
        int val;
        ListNode* next;

        ListNode(int k, int v)
            : key(k),val(v),next(nullptr){};
    };

    static const int SIZE =1009;
    ListNode* bucket[SIZE];

    int hash(int key){
        return key%SIZE;
    }

public:
    MyHashMap() {
        for(int i=0;i<SIZE;i++){
            bucket[i]=nullptr;
        }
    }
    
    void put(int key, int value) {
        int idx=hash(key);

        ListNode* cur=bucket[idx];

        while(cur){
            if(cur->key==key){
                cur->val=value;
                return;
            }
            cur=cur->next;
        }      

        //firt case
        ListNode* node=new ListNode(key,value);
        node->next=bucket[idx];
        bucket[idx]= node;

    }
    
    int get(int key) {
        int idx=hash(key);

        ListNode* cur=bucket[idx];

        while(cur){
            if(cur->key==key){
                return cur->val;
            }
            cur=cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx=hash(key);

        ListNode* cur=bucket[idx];
        ListNode* prev=nullptr;

        while(cur){
            if(cur->key==key){
                if(prev){
                    prev->next=cur->next;
                }else{
                    //remove first one
                    bucket[idx]=cur->next;
                }
            }

            prev=cur;
            cur=cur->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
