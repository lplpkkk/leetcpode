/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MIN(a,b) ((a)<(b)?(a):(b))
int ans=INT_MAX;
int pre=-1;

void inorder(struct TreeNode* node){
    if(node==NULL){
        return;
    }
    //traverse left tree
    inorder(node->left);

    if(pre!=-1){
        ans=MIN(ans,labs((node->val)-pre));
    }
    pre=node->val;

    //traverse right tree
    inorder(node->right);

    return;
}

int getMinimumDifference(struct TreeNode* root) {
    ans=INT_MAX;
    pre=-1;
    inorder(root);
    return ans;
}
