/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void enq(struct TreeNode** q, struct TreeNode* node, int idx){
    q[idx]=node;
    return;
}

struct TreeNode* deq(struct TreeNode** q, int idx){
    return q[idx];
}

int countNodes(struct TreeNode* root) {
    if(!root){
        return 0;
    }

    int front=0;
    int rear=0;
    int ans=0;   
    
    struct TreeNode* q[50000];
    enq(q,root,0);
    rear++;

    while(rear>front){
        int this_lv=(rear-front);
        struct TreeNode* tmp=NULL;

        for(int i=0;i<this_lv;i++){
            tmp=deq(q,front);
            ans++;
            front++;

            if(tmp->left){
                enq(q,tmp->left,rear);
                rear++;
            }
            if(tmp->right){
                enq(q,tmp->right,rear);
                rear++;
            }
        }    
    }

    return ans;
}
