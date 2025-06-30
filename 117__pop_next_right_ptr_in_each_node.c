/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {

    if(!root){
        return NULL;
    }
    
	struct Node* q[60000];
    struct Node* prev=NULL;
    int front=0;
    int back=0;
    
    q[back++]=root;

    while(front<back){
        int lv_size=back-front;
        prev=NULL;

        for(int i=0;i<lv_size;i++){
            struct Node* tmp=q[front++];

            if(prev){
                prev->next=tmp;
            }
            prev=tmp;

            if(tmp->left){
                q[back++]=tmp->left;
            }
            
            if(tmp->right){
                q[back++]=tmp->right;
            }
        }
        prev->next=NULL;
    }

    return root;   
}
