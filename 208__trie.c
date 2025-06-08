


typedef struct Trie{
    struct Trie* child[26];
    bool is_end; 
} Trie;


Trie* trieCreate() {
    Trie* node=calloc(1,sizeof(Trie));
    return node;
}

void trieInsert(Trie* obj, char* word) {
    int len=strlen(word);
    int idx;
    Trie* tmp=obj;

    for(int i=0;i<len;i++){
        idx=word[i]-'a';
        if(!tmp->child[idx]){
            tmp->child[idx]=trieCreate();
        }
        tmp=tmp->child[idx];
    }
    tmp->is_end=true;

    return;
}

bool trieSearch(Trie* obj, char* word) {
    int len=strlen(word);
    int idx;
    Trie* tmp=obj;

    for(int i=0;i<len;i++){
        idx=word[i]-'a';
        if(tmp->child[idx]){
            tmp=tmp->child[idx];
        }else{
            return false;
        }
    }
    return tmp->is_end;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    int len=strlen(prefix);
    int idx;
    Trie* tmp=obj;

    for(int i=0;i<len;i++){
        idx=prefix[i]-'a';
        if(tmp->child[idx]){
            tmp=tmp->child[idx];
        }else{
            return false;
        }
    }
    return true;
}

void trieFree(Trie* obj) {
    for(int i=0;i<26;i++){
        if(obj->child[i]){
            trieFree(obj->child[i]);
        }
    }
    free(obj);
    return;
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
