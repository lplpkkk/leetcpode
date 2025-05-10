/**
 * Definition for a binary tree node.
 * struct TreeNode {
0 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 // start from 21:37, may 7th
 #if(0)
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // handle the null pointer 
    if ((p==NULL) && (q==NULL)){
        return true;
    }else if ((p==NULL) || (q==NULL)){
        return false;
    }

    //check the single node here
    if(p->val!=q->val){
        return false;
    }

    //p and q are non-null tree
    // check layer by layer
    // check next layer is null or not
    do{
        if(p->left==NULL){
            if(q->left!=NULL){
                return false;
            }else{
                //check pass here
                // break the loop;
                break;
            }

        }else{
            if(q->left==NULL){
                return false;
            }else{
                // q and q's left child are non-null
                if(p->left->val==q->left->val){
                    // check pass here
                    p=p->left;
                    q=q->left;
                    //continue the loop
                }else{
                    return false;
                }
            }
        }
    }while ((p->left!=NULL)&&(q->left!=NULL));

    do{
        if(p->right==NULL){
            if(q->right!=NULL){
                return false;
            }else{
                //check pass here
                // break the loop;
                break;
            }

        }else{
            if(q->right==NULL){
                return false;
            }else{
                // q and q's left child are non-null
                if(p->right->val==q->right->val){
                    // check pass here
                    p=p->right;
                    q=q->right;
                    //continue the loop
                }else{
                    return false;
                }
            }
        }
    }while((p->right!=NULL)&&(q->right!=NULL));
    
    //this is the case that only node case (non-child)
    return true;
    
}
#else
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if ((p==NULL) && (q==NULL)){
        return true;
    }else if ((p==NULL) || (q==NULL)){
        return false;
    }

    //check the single node here
    if(p->val!=q->val){
        return false;
    }

    return (isSameTree(q->left,p->left) && isSameTree(q->right,p->right));
}
#endif
