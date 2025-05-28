typedef struct map{
    int key;
    int v;
    UT_hash_handle hh;
}map;

bool isAnagram(char* s, char* t) {
    int i;
    int len_s=strlen(s);
    int len_t=strlen(t);
    map* m=NULL;
    map* found=NULL;
    int idx;

    if(len_s!=len_t){
        return false;
    }
    
    for(i=0;i<len_s;i++){
        idx=s[i]-'a';
        HASH_FIND_INT(m, &idx, found);
        if(!found){
            map* tmp=malloc(sizeof(map));
            tmp->v=1;
            tmp->key=idx;
            HASH_ADD_INT(m, key, tmp);
        }else{
            found->v+=1;
        }
    }    

    
    for(i=0;i<len_t;i++){
        idx=t[i]-'a';
        HASH_FIND_INT(m, &idx, found);
        if ((!found) || (found->v==0)){
            return false;
        }
        
        found->v-=1;
    
    }

    return true;
}
