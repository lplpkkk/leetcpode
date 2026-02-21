/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* prev=NULL; 

bool helper(struct TreeNode* root) {
    if(root==NULL){
        return true;
    }

    if(!helper(root->left)){
        return false;
    }
    
    if (prev!=NULL){
        if(root->val<=prev->val){
            return false;
        }
    }
    prev=root;

    return helper(root->right);

}

bool isValidBST(struct TreeNode* root) {
    prev=NULL;
    return helper(root);
}
