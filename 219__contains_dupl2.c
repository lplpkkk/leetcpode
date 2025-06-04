typedef struct map{
    int key;
    UT_hash_handle hh;
}map;

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if(k==0){
        return false;
    }

    map* m=NULL;
    map* found=NULL;

    for(int i=0;i<numsSize;i++){
        HASH_FIND_INT(m,&nums[i],found);
        if(found){
            HASH_DEL(m,found);
            free(found);
            return true;
        }else{
            map* e=malloc(sizeof(map));
            e->key=nums[i];
            HASH_ADD_INT(m,key,e);

            if(i>=k){
                //evict 1st hash val
                HASH_FIND_INT(m,&nums[i-k],found);
                if(found){
                    HASH_DEL(m,found);
                    free(found);
                }
                
            }           
        }
    }

    return false;


}
