/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct ListNode* g_head;

struct TreeNode* build_tree(int start, int end){
    if(start>end) return NULL;

    int mid=(start+end)/2;
    struct TreeNode* left=build_tree(start, mid-1);
    //struct TreeNode* root=malloc(sizeof(struct TreeNode));
    struct TreeNode* root=calloc(1,sizeof(struct TreeNode));
    root->val=g_head->val;
    root->left=left;

    g_head=g_head->next;
    
    struct TreeNode* right=build_tree(mid+1, end);
    root->right=right;

    
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int len=0;
    struct ListNode* cur=head;

    while(cur){
        len++;
        cur=cur->next;
    }

    g_head=head;
    return build_tree(0,len-1);
    
}
