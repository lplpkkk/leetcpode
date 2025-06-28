#define BIT(x) (1u<<x)

typedef struct trie{
    struct trie* child[2]; //for 0 and 1
}trie;

trie* create_trie(){
    trie* node=(trie*)calloc(1,sizeof(trie));
    return node;
}


void insert(trie* root, int val){
    trie *cur=root;

    for(int i=31;i>=0;i--){
        int bit=(val>>i)&1;
        if(!cur->child[bit]){
            cur->child[bit]=create_trie();
        }
        cur=cur->child[bit];
    }
}

int query(trie* root, int val){
    trie* cur=root;
    int xorval=0;

    for(int i=31;i>=0;i--){
        int b = (val>>i)&1  ;
        int tog_b = b^1;

        if(cur->child[tog_b]){
            xorval|=(1u<<i);
            cur=cur->child[tog_b];
        }else{
            cur=cur->child[b];
        }
    }
    return xorval;
}

void free_trie(trie* root){

    if(!root){
        return;
    }

    free(root->child[0]);
    free(root->child[1]);    
    free(root);
}

int findMaximumXOR(int* nums, int numsSize){
    trie* root=create_trie();
    int maxxor=0;
    insert(root,nums[0]);

    for(int i=1;i<numsSize;i++){
        int curxor=query(root,nums[i]);
        if(curxor>maxxor){
            maxxor=curxor;
        }
        insert(root,nums[i]);
    }

    free_trie(root);

    return maxxor;
}
