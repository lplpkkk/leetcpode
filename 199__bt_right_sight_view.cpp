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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        
        queue<TreeNode*> q;
        vector<int> ans;

        q.push(root);
        while(!q.empty()){
            int lvsize=q.size();
            ans.push_back(q.back()->val);
            
            for(int i=0;i<lvsize;i++){
                TreeNode* this_node=q.front();
                if(this_node->left!=nullptr){
                    q.push(this_node->left);
                }
                
                if(this_node->right!=nullptr){
                    q.push(this_node->right);
                }
                q.pop();
            }
        }
        return ans;
    }
};
