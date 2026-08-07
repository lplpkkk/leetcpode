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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur=head;

        while(cur!=NULL && cur->next!=NULL){
            int val=gcd(cur->val,cur->next->val);

            ListNode* newgcd=new ListNode(val,cur->next);
            cur->next=newgcd;

            cur=cur->next->next;
        }
        
        return head;
    }
};
