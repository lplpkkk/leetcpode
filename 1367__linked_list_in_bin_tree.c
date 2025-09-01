/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool dfs(struct TreeNode* root, struct ListNode* head){
    if(!head){
        return true;
    }

    if(!root){
        return false;
    }

    if(root->val!=head->val){
        return false;
    }

    return dfs(root->left,head->next)||dfs(root->right,head->next);

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (!root) return false;
    return dfs(root,head)||isSubPath(head,root->left)||isSubPath(head,root->right);
}
