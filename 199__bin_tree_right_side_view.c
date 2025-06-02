/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


//8:23
#define MAX_SIZE 2000

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int cur_n=0;
    int to_do_n=0;
    struct TreeNode* q[MAX_SIZE];

    if(!root){
        *returnSize=0;
        return NULL;
    }else{
        to_do_n=1;
        
        q[0]=root;       
    }

    int size=0;
    int this_lv_n=(to_do_n-cur_n);
    int* ans=malloc(sizeof(int)*MAX_SIZE);   

    while(cur_n<to_do_n){
        this_lv_n=(to_do_n-cur_n);
        for(int i=0;i<this_lv_n;i++){
            // dequeue
            struct TreeNode* node=q[cur_n];
            cur_n++;
            
            // chk the rightest
            if(i== (this_lv_n-1)){
                ans[size++]=node->val;
            }

            // prepare next round
            if(node->left){
                //enqueue
                q[to_do_n]=node->left;
                to_do_n++;
            }
            if(node->right){
                //enqueue
                q[to_do_n]=node->right;
                to_do_n++;
            }
        }
    }

    *returnSize=size;
    return ans;

}
