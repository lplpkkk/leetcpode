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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==NULL){
            return {};
        }

       vector<vector<int>> ans;
       queue<TreeNode*> q;

        bool direction=true;//use to decide order

        q.push(root);
        
        while(!q.empty()){
            int len=q.size();
            vector<int> this_layer(len);

            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();

                int idx=(direction==true)?i:(len-1-i);
                this_layer[idx]=node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            direction=!direction; 
            ans.push_back(this_layer);
        }
        return ans;
    }
};
