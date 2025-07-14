/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int* count, int* ans){
    if(!root){
        return;
    }

    count[root->val]++;
    if(!root->left && !root->right){
        int odd=0;
        for(int i=0;i<=9;i++){
            if(count[i]&1){
                odd++;
            }
        }
        if(odd<=1){
            (*ans)++;
        }
    }

    dfs(root->left,count,ans);
    dfs(root->right,count,ans);
    
    count[root->val]--;
    return;
}


int pseudoPalindromicPaths (struct TreeNode* root) {
    int count[10]={0};
    int ans=0;
    dfs(root,count,&ans);
    return ans;    
}
