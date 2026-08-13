class LRUCache {
private:
    struct ListNode{
        int key;
        int val;
        ListNode* next;
        ListNode* prev;

        ListNode(int k,int v): key(k),val(v),next(nullptr),prev(nullptr){};
    };

    int lim;
    
    ListNode* head;
    ListNode* tail;

    unordered_map<int, ListNode*> map;

public:

    void rmnode(ListNode* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void addfront(ListNode* node){
        node->next=head->next;
        node->prev=head;

        head->next->prev=node;
        head->next=node;
    }

    void movetofront(ListNode* node){
        rmnode(node);
        addfront(node);
    }

    LRUCache(int capacity) {
        this->lim=capacity;
        head=new ListNode(0,0);
        tail=new ListNode(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()){
            return -1;
        }

        ListNode* node=map[key];
        movetofront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            ListNode* node=map[key];
            node->val=value;
            movetofront(node);
            return;
        }

        ListNode* newnode=new ListNode(key,value);
        map[key]=newnode;
        addfront(newnode);

        if(map.size()>lim){
            ListNode* lru=tail->prev;
            rmnode(lru);
            map.erase(lru->key);

            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
