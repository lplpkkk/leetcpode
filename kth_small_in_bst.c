/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 // l --> r --> r

int cnt=0, result=0;
void inorder(struct TreeNode* node, int k){
    
    if(!node){
        return;
    }
    
    inorder(node->left,k);

    //printf("%d-->%d\n",cnt,node->val);
    cnt++;
    if(cnt==(k)){
        result=node->val;
        return;
    }
    
    inorder(node->right,k);
}

int kthSmallest(struct TreeNode* root, int k) {
    cnt=0;
    inorder(root,k);
    return result;
}
