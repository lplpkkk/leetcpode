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

        if(root==nullptr){
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        int left2right=1;

        q.push(root);

        while(!q.empty()){
            int lvsize=q.size();
            vector<int> tmp;

            for(int i=0;i<lvsize;i++){
                TreeNode* this_node=q.front();

                tmp.push_back(this_node->val);
                if(this_node->left){
                    q.push(this_node->left);
                }
                if(this_node->right){
                    q.push(this_node->right);
                }
                q.pop();
            }

            if(!left2right){
                reverse(tmp.begin(),tmp.end());
            }

            left2right=!left2right;
            ans.push_back(tmp);
            
        }

        return ans;
        

    }
};
