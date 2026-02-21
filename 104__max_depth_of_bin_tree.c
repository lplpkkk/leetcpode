/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root==NULL){
        return 0;
    }    
    int l_depth=maxDepth(root->left);
    int r_depth=maxDepth(root->right);
    return ((l_depth>r_depth)?l_depth:r_depth)+1;
}
