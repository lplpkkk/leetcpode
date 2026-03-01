/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto l: lists){
            if(l) pq.push(l);
        }      

        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;

        while(!pq.empty()){
            ListNode* this_node=pq.top();
            pq.pop();

            tail->next=this_node;
            tail=tail->next;

            if(this_node->next){
                pq.push(this_node->next);
            }
        }

        return dummy->next;
    }
};
