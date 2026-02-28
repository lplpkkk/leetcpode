class Solution {
public:
 

    Node* insert(Node* head, int insertVal) {
        Node* node=new Node(insertVal);

        if(head==nullptr){
            node->next=node;
            return node;
        } 

        //handle normal case, end case
        Node* prev=head;
        Node* cur=head->next;

        while(cur!=head){
            if( (prev->val<=insertVal&&insertVal<=cur->val)
                || ((prev->val>cur->val)&&( insertVal>=prev->val || insertVal<=cur->val))){
                break;
            }
            prev=cur;
            cur=cur->next;
        }
        prev->next=node;
        node->next=cur;

        return head;
    }
}
