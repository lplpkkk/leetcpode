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
    vector<string> ans;

    void dfs (TreeNode* this_node, string this_str){

        if(this_node==nullptr) return;

        //this_str.push_back("->"+to_string(this_node->val));
        if(this_str.empty()){
            this_str+=to_string(this_node->val);
        }else{
            this_str=this_str+"->"+to_string(this_node->val);
        }

        if( (this_node->left==nullptr) && (this_node->right==nullptr)){
            ans.push_back(this_str);
            return;
        }
        
        dfs(this_node->left, this_str);
        dfs(this_node->right, this_str);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;      
    }
};
