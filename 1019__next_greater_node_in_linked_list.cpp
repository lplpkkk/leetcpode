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

/* 
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* cur=head;
        stack<pair<int, ListNode*>> st;

        st.push({cur->val,cur});
        cur=cur->next;

        while(cur){
            vector<pair<int,ListNode*>> need_to_push_back;
            while(!st.empyt()){
                int last_val=st.top().first;
                ListNode* last_node=st.top().second;

                st.pop();
                if(last_val<cur->val){
                    last_node->val=cur->val;    
                }else{
                    need_to_push_back.push_back({last_val,last_node});
                }
            }
            for(int i=0;i<need_to_push_back.size();i++){
                st.push(need_to_push_back[i]);
            }

            cur=cur->next;
        }

        cur=head;
        while(cur){
            ans.push_back(cur->val);
            cur=cur->next;
        }
        
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> nums;
        ListNode* cur=head;

        while(cur){
            nums.push_back(cur->val);
            cur=cur->next;
        }

        int n=nums.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                ans[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
