/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool chk(struct TreeNode* a, struct TreeNode* b){

    if(!a && !b){
        return true;
    }

    if((!a->left)&& (b->right)
        ||(!a->right)&& (b->left)
        ||(a->left)&& (!b->right)
        ||(a->right)&& (!b->left)
    ){
        return false;
    }

    if(a->val!=b->val){
        return false;
    }

    return (chk(a->left,b->right) 
            && chk(a->right,b->left ));
}

bool isSymmetric(struct TreeNode* root) {
    struct TreeNode* l=root->left;
    struct TreeNode* r=root->right;
    
    if(!l && !r){
        return true;
    }

    if((l && !r) ||(!l && r)){
        return false;
    }

    return chk(l,r);
}
