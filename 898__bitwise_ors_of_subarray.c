typedef struct hash_set{
    int val;
    UT_hash_handle hh;
}hash_set;

void add(hash_set** set, int val){
    hash_set * found;
    HASH_FIND_INT(*set,&val,found);

    if(!found){
        found=malloc(sizeof(hash_set));
        found->val=val;
        HASH_ADD_INT(*set,val,found);
    }
    
    return;
}

void free_set(hash_set* set){
    hash_set *cur, *tmp;
    HASH_ITER(hh, set,cur,tmp){
        HASH_DEL(set,cur);
        free(cur);
    }
    return;
}

int subarrayBitwiseORs(int* arr, int arrSize) {
    hash_set* seen=NULL;
    hash_set* cur=NULL;

    for(int i=0;i<arrSize;i++){
        hash_set* next=NULL;
        add(&next, arr[i]);

        hash_set* it;
        for(it=cur;it!=NULL;it=it->hh.next){
            int val=arr[i]|it->val;
            add(&next,val);           
        }

        for(it=next;it!=NULL;it=it->hh.next){
            add(&seen,it->val);
        }

        free_set(cur);
        cur=next;
    }

    int result=HASH_COUNT(seen);
    free_set(cur);
    free_set(seen);
    return result;
}
