/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int ans=0;
    void dfs(TreeNode* root, int v){
        if(root==nullptr){
            return;
        }    
        
        v=(v<<1)|root->val;

        if((root->left==nullptr) && (root->right==nullptr)){
            ans+=v;
        }

        dfs(root->left,v);
        dfs(root->right,v);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        dfs(root,0);
        return ans;
    }
};
