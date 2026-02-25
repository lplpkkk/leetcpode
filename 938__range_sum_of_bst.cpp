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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr){
            return 0;
        }
        int this_val=root->val;
        if(this_val>=low && this_val<=high){
            return this_val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }else if (this_val<low){
            return rangeSumBST(root->right,low,high);
        }else{
            return rangeSumBST(root->left,low,high);
        }
    }
};
