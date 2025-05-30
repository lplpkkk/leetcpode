typedef struct map{
    int key; 
    char name[32];    
    UT_hash_handle hh;
}map;

typedef struct rv_map{
    char name[32];    
    int key; 
    UT_hash_handle hh;
}rv_map;

char* get_word(char** h){
    char* cur=*h;
    int i=0;

    while((*(cur+i)!='\0') && (*(cur+i)!=' ')){
        i++;
    }

    if(*(cur+i)==' '){
        *(cur+i)='\0';
        *h=(cur+i+1);
    }else{
        *h=(cur+i);
    }

    return (cur);
}

bool wordPattern(char* pattern, char* s) {

    //for val in *pattern
    //  hash_find_int
    //  if(not in map)
    //      word = get the 'ith' word in s
    //          also update cursor in s
    //      if(!word) return false

    //      tmp->name=word;
    //      hash_add_int(map, &key, tmp)
    // if(!cursor) return false
    // else return true;
    //
    // 

    map* m=NULL;
    rv_map* rv_m=NULL;

    int i=0;
    int len_p=strlen(pattern);
    char* s_cur=s;
    int key;
    //char* this_word=get_word (&s_cur);

    for(i=0;i<len_p;i++){
        if (*s_cur == '\0') return false;

        char* this_word=get_word (&s_cur);
        map* tmp=NULL;
        key=pattern[i];
        HASH_FIND_INT(m, &key, tmp);

        if(!tmp){
            // reverse map check
            
            rv_map *rv_tmp=NULL;
            HASH_FIND_STR(rv_m, this_word, rv_tmp);
            if(rv_tmp){
                return false;
            }

            tmp=malloc(sizeof(map));
            tmp->key=pattern[i];
            strcpy(tmp->name, this_word);
            HASH_ADD_INT(m, key, tmp);

            rv_tmp=malloc(sizeof(rv_map));
            strcpy(rv_tmp->name,this_word);
            rv_tmp->key=pattern[i];
            HASH_ADD_STR(rv_m,name,rv_tmp);
            
        }else{
            //if((tmp->name)!=get_word(&s_cur)){
            if(strcmp(tmp->name,this_word)){
                return false;
            }
        }

        
        
    }

    if(*s_cur !='\0'){
        return false;
    }else{
        return true;
    }
    




}
