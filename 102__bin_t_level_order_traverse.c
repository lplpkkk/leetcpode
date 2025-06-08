/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 #define MAX_SIZE 2000
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    if(root==NULL){
        *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;
    }

    struct TreeNode* q[MAX_SIZE];
    int** result=malloc(sizeof(int*)*MAX_SIZE);
    *returnColumnSizes=malloc(sizeof(int)*MAX_SIZE);

    int front=0, rear=0, cur_n_idx=0;
    int height=0;

    q[rear++]=root;

    while(front<rear){
        int level_size=(rear-front);
        result[height]=malloc(sizeof(int)*level_size);

        for(int i=0;i<level_size;i++){
            struct TreeNode* tmp=q[front];
            result[height][i]=tmp->val;  
            front++;

            if(tmp->left){
                q[rear++]=tmp->left;
            }
            if(tmp->right){
                q[rear++]=tmp->right;
            }
        }
        (*returnColumnSizes)[height]=level_size;
        height++;
         
    }
    *returnSize=height;
    return result;
}
