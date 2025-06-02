
typedef struct list {
    int key;
    struct list* prev;
    struct list* next;
} list;

typedef struct map {
    int key;
    int val;
    list* node;           // pointer to corresponding node in list
    UT_hash_handle hh;
} map;

typedef struct {
    int cap;
    int cur;
    map* hash;            // key -> val
    list* head;           // least recently used
    list* tail;           // most recently used
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = malloc(sizeof(LRUCache));
    cache->cap = capacity;
    cache->cur = 0;
    cache->hash = NULL;
    cache->head = NULL;
    cache->tail = NULL;
    return cache;
}

// move a node to the tail (most recently used)
void move_to_tail(LRUCache* obj, list* node) {
    if (obj->tail == node) return;

    // detach node
    if (node->prev) node->prev->next = node->next;
    else obj->head = node->next;

    if (node->next) node->next->prev = node->prev;
    else obj->tail = node->prev;

    // attach to tail
    node->prev = obj->tail;
    node->next = NULL;
    if (obj->tail) obj->tail->next = node;
    obj->tail = node;

    if (!obj->head) obj->head = node;
}

int lRUCacheGet(LRUCache* obj, int key) {
    map* found = NULL;
    HASH_FIND_INT(obj->hash, &key, found);
    if (!found) return -1;

    move_to_tail(obj, found->node);
    return found->val;
}

void evict(LRUCache* obj) {
    if (!obj->head) return;

    list* lru_node = obj->head;
    int del_key = lru_node->key;

    // remove from list
    obj->head = lru_node->next;
    if (obj->head) obj->head->prev = NULL;
    else obj->tail = NULL;

    free(lru_node);

    // remove from hash
    map* found = NULL;
    HASH_FIND_INT(obj->hash, &del_key, found);
    if (found) {
        HASH_DEL(obj->hash, found);
        free(found);
    }

    obj->cur--;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    map* found = NULL;
    HASH_FIND_INT(obj->hash, &key, found);

    if (found) {
        // update value and move to tail
        found->val = value;
        move_to_tail(obj, found->node);
        return;
    }

    if (obj->cur == obj->cap) {
        evict(obj);
    }

    // insert new key
    list* new_node = malloc(sizeof(list));
    new_node->key = key;
    new_node->prev = obj->tail;
    new_node->next = NULL;
    if (obj->tail) obj->tail->next = new_node;
    obj->tail = new_node;
    if (!obj->head) obj->head = new_node;

    map* new_map = malloc(sizeof(map));
    new_map->key = key;
    new_map->val = value;
    new_map->node = new_node;
    HASH_ADD_INT(obj->hash, key, new_map);

    obj->cur++;
}

void lRUCacheFree(LRUCache* obj) {
    // free hash
    map *curr, *tmp;
    HASH_ITER(hh, obj->hash, curr, tmp) {
        HASH_DEL(obj->hash, curr);
        free(curr);
    }

    // free list
    list* l = obj->head;
    while (l) {
        list* next = l->next;
        free(l);
        l = next;
    }

    free(obj);
}

#if(0)
typedef struct map{
    int key;
    int val;
    UT_hash_handle hh;    
}map;

typedef struct list{
    int val;
    struct list* next;
    struct list* prev;
}list;

typedef struct {
    int cap;
    int cur;
    map* head;
    list* list;    
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* tmp=malloc(sizeof(LRUCache));
    tmp->cap=capacity;
    tmp->cur=0;
    tmp->head=NULL;
    tmp->list=NULL;
    return tmp;
}

int lRUCacheGet(LRUCache* obj, int key) {
    map* m=obj->head;
    map* found=NULL;
    HASH_FIND_INT(m,&key,found);
    if(found){
        return found->val;
    }else{
        return -1;
    }
}

// old --> kind_of_old --> new
//
void evict( LRUCache *obj){    
    //kill the first
    list* l=obj->list;
    l->next->prev=NULL;
    obj->list=l->next;
    free(l);
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(obj->cur>=obj->cap){
        evict(obj);
    }
    
    map* m=obj->head;

    // add hash map
    map* this_node=malloc(sizeof(map));
    this_node->key=key;
    this_node->val=value;
    HASH_ADD_INT(m,key,this_node);

    //add to list
    list* l=obj->list;
    list* this_node_l=malloc(sizeof(list));
    this_node_l->val=value;
    this_node_l->next=NULL;
    this_node_l->prev=NULL;

    while(l->next){
        l=l->next;
    }

    this_node_l->prev=l->next;
    l->next=this_node_l;

    return;
}

void lRUCacheFree(LRUCache* obj) {
    map* m=obj->head;
    list* l=obj->list;

    map *a, *b;
    HASH_ITER(hh,m,a,b){
        HASH_DEL(m,a);
    };

    while(l){
        list* tmp=l->next;
        free(l);
        l=tmp;
    }

    return;
}
#endif



#if(0)
typedef struct list{
    int key;
    struct list* next;
}list;

typedef struct {
    int key;
    int val;
    //int ts;//this is used for tracking current node ts
    list* node;
    int cnt;//this is used for tracking current node current node 
    int cap;//this is used for trakcing the capacity
    UT_hash_handle hh;
} LRUCache;



LRUCache* lRUCacheCreate(int capacity) {
    LRUCache * map=malloc(sizeof(LRUCache));
    map->cap=capacity;
    map->cnt=0;
    map->node=NULL;
    return map;
}

int lRUCacheGet(LRUCache* obj, int key) {
    LRUCache *found=NULL;
    HASH_FIND_INT(obj,&key,found);

    if(found){
        return found->val;
    }else{
        return -1;
    }

}

list* insert_front(list* l, list* new_node){
    list* cur=new_node;

    cur->next=l;
    return cur;
}

list* kill_front(list* l){
    list* cur=l->next;
    free(l);
    return cur;
}

void lRUCachePut(LRUCache* obj, int key, int value) {

    if(obj->cnt==obj->cap){
        //evict
        LRUCache* found;
        HASH_FIND_INT(obj, &obj->node->key, found);
        HASH_DEL(obj,found);

        obj->node=kill_front(obj->node);
        obj->cnt--;
    }

    LRUCache *new_node=malloc(sizeof(LRUCache));
    new_node->key=key;
    new_node->val=value;
    HASH_ADD_INT(obj,key,new_node);
    obj->cnt++;

}

void lRUCacheFree(LRUCache* obj) {
    // pretend free all?
    LRUCache* cur, *tmp;
    HASH_ITER(hh, obj, cur,tmp){
        HASH_DEL(obj,cur);
        free(cur);
    }

    return;
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
#endif
