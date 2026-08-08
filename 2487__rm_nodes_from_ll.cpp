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
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> st;

        while(head){
            while(!st.empty()&&st.back()->val<head->val){
                st.pop_back();
            }

            st.push_back(head);
            head=head->next;
        }

        for(int i=0;i<st.size()-1;i++){
            st[i]->next=st[i+1];
        }

        st.back()->next=nullptr;

        return st[0];
    }
};
