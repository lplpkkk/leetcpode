bool check_match(char* p, char* key, int key_len){
    for(int i=0;i<key_len;i++){
        if(*(p+i)!=*(key+i)){
            return false;
        }
    }
    return true;
}

int strStr(char* haystack, char* needle) {
    int len_pool=strlen(haystack);
    int len_key=strlen(needle);

    if(len_key == 0) return 0; 
    if(len_pool<len_key) return -1;

    for(int i=0;i<=(len_pool-len_key);i++){
        char* p=haystack+i;
        if(check_match(p,needle,len_key)){
            return i;
        }
    }

    return -1;
}
