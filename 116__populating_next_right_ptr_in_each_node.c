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
	if(!root) return NULL;

    struct Node* queue[5000];
    int front=0, rear=0;

    queue[rear++]=root;
    
    while(front<rear){
        int size=(rear-front);
        struct Node* prev=NULL;

        for(int i=0;i<size;i++){
            struct Node* node=queue[front++];
            if(prev){
                prev->next=node;
            }
            prev=node;
            if(node->left){
                queue[rear++]=node->left;
            }
            if(node->right){
                queue[rear++]=node->right;
            }
        }

         prev->next=NULL;
    }

    return root;
}
