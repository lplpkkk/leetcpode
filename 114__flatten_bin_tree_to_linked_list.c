/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void flatten(struct TreeNode* root) {
    while(root){
        if(root->left){
            struct TreeNode* pre=root->left;
            while(pre->right){
                pre=pre->right;
            }
            pre->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        root=root->right;
    }
}
