/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct{
    int key;
    int idx;
    UT_hash_handle hh;
}map;

map* m=NULL;
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* dfs(int* preorder, int preStart, int preEnd, int inStart, int inEnd){
    if (preStart > preEnd || inStart > inEnd) return NULL;

    int root_val=preorder[preStart];
    struct TreeNode* root=newNode(root_val);
    map* item;
    HASH_FIND_INT(m,&root_val,item);

    //item->idx is root idx in inorder list
    int inIdx=item->idx;
    int leftTreeIdx=inIdx-inStart;
    
    root->left=dfs(preorder,preStart+1,preStart+leftTreeIdx,inStart,inIdx-1);
    root->right=dfs(preorder,preStart+leftTreeIdx+1,preEnd,inIdx+1,inEnd);

    return root;
}


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {

    for(int i=0;i<inorderSize;i++){
        map* item=malloc(sizeof(map));
        item->key=inorder[i];
        item->idx=i;
        HASH_ADD_INT(m,key,item);
    }

    struct TreeNode* ans=dfs(preorder,0,preorderSize-1,0,inorderSize-1);

    map* cur,*tmp;
    HASH_ITER(hh,m,cur,tmp){
        HASH_DEL(m,cur);
        free(cur);
    }

    return ans;
}
