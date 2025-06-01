typedef struct map{
    int key;
    int val;
    UT_hash_handle hh;
}map;

int calc(int n){
    int ans=0;
    int this_dig=0;

    while(n){
        this_dig=n%10;
        ans+=(this_dig)*(this_dig);
        n/=10;
    }

    return ans;
}

bool isHappy(int n) {
    map* m=NULL;
    int cur=n;

    while(cur!=1){
        map *found=NULL;
        HASH_FIND_INT(m,&cur,found);

        if(found){
            return false;
        }else{
            map* e=malloc(sizeof(map));
            e->key=cur;
            e->val=1; //not important
            HASH_ADD_INT(m,key,e);
        }

        //prepare next
        cur=calc(cur);
    }
    
    map* cur_m, *tmp;
    HASH_ITER(hh,m,cur_m,tmp){
        HASH_DEL(m,cur_m);
        free(cur_m);
    }

    return true;
}
