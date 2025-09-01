/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct hash_item{
    char key[11];
    int cnt;
    UT_hash_handle hh;
}hash_item;

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    int len=strlen(s);
    *returnSize=0;

    if(len<10){
        return NULL;
    }    

    hash_item *hash=NULL, *item;
    char ** res=malloc(sizeof(char*)*(len-9));

    for(int i=0;i<len;i++){
        char sub[11];
        strncpy(sub,s+i,10);
        sub[10]='\0';

        HASH_FIND_STR(hash,sub,item);
        if(!item){
            item=malloc(sizeof(hash_item));
            strcpy(item->key,sub);
            item->cnt=1;
            HASH_ADD_STR(hash,key,item);
        }else{
            item->cnt++;
            if(item->cnt==2){
                res[*returnSize]=malloc(sizeof(char)*11);
                strcpy(res[*returnSize],sub);
                (*returnSize)++;
            }
        }
    }

    hash_item *cur,*tmp;
    HASH_ITER(hh,hash,cur,tmp){
        HASH_DEL(hash,cur);
        free(cur);
    }
    
    return res;
}
