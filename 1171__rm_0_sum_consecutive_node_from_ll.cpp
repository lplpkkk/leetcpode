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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0,head);

        unordered_map<int, ListNode*> map;
        ListNode* cur=&dummy;
        int prefix=0;

        while(cur){
            prefix+=cur->val;
            map[prefix]=cur;
            cur=cur->next;    
        }

        prefix=0;
        cur=&dummy;
        while(cur){
            prefix+=cur->val;
            cur->next=map[prefix]->next;
            cur=cur->next;
        }

        return dummy.next;
    }
};
