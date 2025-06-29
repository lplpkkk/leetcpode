#if(0)
typedef struct map_f{
    int key;
    int counter;
    UT_hash_handle hh;
}map_f;

typedef struct map{
    int key;
    int val;
    UT_hash_handle hh;
}map;

typedef struct dl{
    struct dl* prev;
    struct dl* next;
}dl;

typedef struct {
    int cap;
    int size;
    map* _map;
    map_f* _map_f;
    dl* head;
    dl* tail;
} LFUCache;


LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* this=malloc(sizeof(LFUCache));
    this->cap=capacity;
    this->_map=malloc(sizeof(map));
    this->_map_f=malloc(sizeof(map_f));

    this->head=malloc(sizeof(dl));
    this->tail=malloc(sizeof(dl));

    this->head->prev=NULL;
    this->head->next=this->tail;
    this->tail->prev=this->head;
    this->tail->next=NULL;
}

int lFUCacheGet(LFUCache* obj, int key) {
    map* m=obj->_map;
    map_f* m_f=obj->_map_f;

    map* found;
    HASH_FIND_INT(m, &key, found);

    if(found){
        map_f* found_f;
        HASH_FIND_INT(m_f,&key, found_f);
        found_f->counter++;

        return found->val;
    }else{
        return -1;
    }
}

void evict(LFUCache* obj){

}

void lFUCachePut(LFUCache* obj, int key, int value) {
    map* m=obj->_map;
    map_f* m_f=obj->_map_f;
    
    map* found;
    map_f* found_f;

    HASH_FIND_INT(m, &key, found);
    if(!found){
        found=malloc(sizeof(map));
        found->val=value;
        HASH_ADD_INT(m, key,found);
    }else{
        found->val=value;
    }

    HASH_FIND_INT(m_f, &key, found_f);
    if(!found_f){
        found_f=malloc(sizeof(map_f));
        found_f->counter=1;
        HASH_ADD_INT(m_f,key,found_f);
    }else{
        found_f->counter++;
    }
    
    return;
}

void lFUCacheFree(LFUCache* obj) {
    map* cur,*tmp;
    HASH_ITER(hh,obj->_map,cur,tmp){}
        HASH_DEL(obj->_map,cur);
    }
    free(obj->_map);

    map_f* cur,*tmp;
    HASH_ITER(hh,obj->_map_f,cur,tmp){}
        HASH_DEL(obj->_map_f,cur);
    }
    free(obj->_map_f);

}
#endif

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/


// ---------- 雙向鏈結節點 ----------
typedef struct DLNode {
    int key;
    struct DLNode* prev;
    struct DLNode* next;
} DLNode;

// ---------- 頻率對應的鏈表 ----------
typedef struct FreqList {
    int freq;
    DLNode* head;
    DLNode* tail;
    UT_hash_handle hh;
} FreqList;

// ---------- key → {val, freq, list node ptr} ----------
typedef struct CacheEntry {
    int key;
    int val;
    int freq;
    DLNode* node;  // pointer to node in freq list
    UT_hash_handle hh;
} CacheEntry;

// ---------- LFUCache 本體 ----------
typedef struct {
    int cap;
    int size;
    int min_freq;

    CacheEntry* key_table;   // key → CacheEntry
    FreqList* freq_table;    // freq → doubly linked list
} LFUCache;


// 建立新的 cache 節點
DLNode* create_node(int key) {
    DLNode* node = (DLNode*)malloc(sizeof(DLNode));
    node->key = key;
    node->prev = node->next = NULL;
    return node;
}

// 建立新的 frequency list
FreqList* create_freq_list() {
    FreqList* list = (FreqList*)malloc(sizeof(FreqList));
    list->head = list->tail = NULL;
    return list;
}

// 將 node 加到 freq list 尾巴
void append_node(FreqList* list, DLNode* node) {
    node->prev = node->next = NULL;
    if (!list->tail) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}

// 從 freq list 移除 node
void remove_node(FreqList* list, DLNode* node) {
    if (node->prev) node->prev->next = node->next;
    else list->head = node->next;

    if (node->next) node->next->prev = node->prev;
    else list->tail = node->prev;

    node->prev = node->next = NULL;
}

LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* obj = (LFUCache*)malloc(sizeof(LFUCache));
    obj->cap = capacity;
    obj->size = 0;
    obj->min_freq = 0;
    obj->key_table = NULL;
    obj->freq_table = NULL;
    return obj;
}

int lFUCacheGet(LFUCache* obj, int key) {
    CacheEntry* entry;
    HASH_FIND_INT(obj->key_table, &key, entry);
    if (!entry) return -1;

    // 1. 移除 key 從舊 freq list
    FreqList* old_list;
    HASH_FIND_INT(obj->freq_table, &entry->freq, old_list);
    remove_node(old_list, entry->node);

    // 2. 若舊 list 為空，且是 min_freq，要遞增
    if (!old_list->head && entry->freq == obj->min_freq) {
        obj->min_freq++;
    }

    // 3. 新 freq
    entry->freq++;
    FreqList* new_list;
    HASH_FIND_INT(obj->freq_table, &entry->freq, new_list);
    if (!new_list) {
        new_list = create_freq_list();
        new_list->freq = entry->freq;
        HASH_ADD_INT(obj->freq_table, freq, new_list);
    }

    append_node(new_list, entry->node);
    return entry->val;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    if (obj->cap == 0) return;

    CacheEntry* entry;
    HASH_FIND_INT(obj->key_table, &key, entry);

    if (entry) {
        entry->val = value;
        lFUCacheGet(obj, key);  // promote frequency
        return;
    }

    // 若滿了，需淘汰
    if (obj->size == obj->cap) {
        FreqList* min_list;
        HASH_FIND_INT(obj->freq_table, &obj->min_freq, min_list);
        DLNode* to_evict = min_list->head;

        // 從所有表中移除
        remove_node(min_list, to_evict);
        int evict_key = to_evict->key;
        CacheEntry* del_entry;
        HASH_FIND_INT(obj->key_table, &evict_key, del_entry);
        HASH_DEL(obj->key_table, del_entry);
        free(del_entry->node);
        free(del_entry);
        obj->size--;
    }

    // 插入新 entry
    CacheEntry* new_entry = (CacheEntry*)malloc(sizeof(CacheEntry));
    new_entry->key = key;
    new_entry->val = value;
    new_entry->freq = 1;
    new_entry->node = create_node(key);
    HASH_ADD_INT(obj->key_table, key, new_entry);

    FreqList* list1;
    HASH_FIND_INT(obj->freq_table, &new_entry->freq, list1);
    if (!list1) {
        list1 = create_freq_list();
        list1->freq = 1;
        HASH_ADD_INT(obj->freq_table, freq, list1);
    }
    append_node(list1, new_entry->node);
    obj->min_freq = 1;
    obj->size++;
}

void lFUCacheFree(LFUCache* obj) {
    // 1. 釋放 freq_table 及其中的 linked list nodes
    FreqList *fcur, *ftmp;
    HASH_ITER(hh, obj->freq_table, fcur, ftmp) {
        DLNode* n = fcur->head;
        while (n) {
            DLNode* next = n->next;
            free(n);  // ✅ node 只在這裡釋放一次
            n = next;
        }
        HASH_DEL(obj->freq_table, fcur);
        free(fcur);
    }

    // 2. 釋放 key_table（但不要再釋放 node）
    CacheEntry *cur, *tmp;
    HASH_ITER(hh, obj->key_table, cur, tmp) {
        HASH_DEL(obj->key_table, cur);
        free(cur);  // ❌ 不再 free(cur->node)，避免 double free
    }

    // 3. 釋放 LFUCache 本體
    free(obj);
}
