/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur=head;

        while(cur!=NULL){
            if(cur->child!=NULL){
                Node* next_node=cur->next;
                Node* child=cur->child;
                
                cur->next=child;
                child->prev=cur;
                cur->child=NULL;
                
                Node* tail=child;
                while(tail->next!=NULL){
                    tail=tail->next;
                }
                
                tail->next=next_node;
                if(next_node!=NULL){
                    next_node->prev=tail;
                }
            }
            cur=cur->next;    
        }
        return head;
    }
};
