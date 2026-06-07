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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> nodemap;
        unordered_set<int> children;

        for(const auto& d:descriptions){
            int parentv=d[0];
            int childv=d[1];
            int lv=d[2];

            if(nodemap.find(parentv)==nodemap.end()){
                nodemap[parentv]=new TreeNode(parentv);
            }
            
            if(nodemap.find(childv)==nodemap.end()){
                nodemap[childv]=new TreeNode(childv);
            }

            if(lv==1){
                nodemap[parentv]->left=nodemap[childv];
            }else{
                nodemap[parentv]->right=nodemap[childv];
            }

            children.insert(childv);
        }

        for(const auto& d:descriptions){
            int parentv=d[0];
            if(children.find(parentv)==children.end()){
                return nodemap[parentv];
            }
        }

        return nullptr;
    }
};
