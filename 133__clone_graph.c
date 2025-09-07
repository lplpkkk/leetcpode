/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
typedef struct {
    struct Node* key;
    struct Node* val;
    UT_hash_handle hh;
}hash_item;

hash_item* visited=NULL;

struct Node* dfs(struct Node* node){

    if(!node) return NULL;

    hash_item* item;
    HASH_FIND_PTR(visited,&node,item);
    if(item) return item->val;

    struct Node* clone=malloc(sizeof(struct Node));
    clone->val=node->val;
    clone->numNeighbors=node->numNeighbors;
    clone->neighbors=malloc(sizeof(struct Node*)*node->numNeighbors);

    item=malloc(sizeof(hash_item));
    item->key=node;
    item->val=clone;

    HASH_ADD_PTR(visited,key,item);

    for(int i=0;i<node->numNeighbors;i++){
        clone->neighbors[i]=dfs(node->neighbors[i]);
    }

    return clone;
}


struct Node *cloneGraph(struct Node *s) {
    visited=NULL;
    struct Node* clone=dfs(s);
    hash_item* cur,*tmp;
    HASH_ITER(hh,visited,cur,tmp){
        HASH_DEL(visited,cur);
        free(cur);
    }
    visited=NULL;
    return clone;
}
