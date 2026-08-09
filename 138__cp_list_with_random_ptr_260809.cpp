/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head){
            return nullptr;
        }

        //insert
        Node* cur=head;
        while(cur){
            Node* clone=new Node(cur->val);
            clone->next=cur->next;
            cur->next=clone;
            cur=clone->next;
        }

        //adjust copy link
        cur=head;
        while(cur){
            Node* clone=cur->next;
            clone->random=cur->random?cur->random->next:nullptr;
            cur=cur->next->next;
        }

        //separate nodes
        cur=head;
        Node* ans=cur->next;

        while(cur){
            Node* clone=cur->next;

            cur->next=clone->next;

            if(clone->next){
                clone->next=clone->next->next;
            }

            cur=cur->next;
        }

        return ans;
    }
};
