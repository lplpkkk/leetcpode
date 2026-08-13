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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }


        //reverse 2nd part;
        ListNode* pal=slow;
        ListNode* prev=nullptr;

        while(pal){
            ListNode* tmp=pal->next;
            pal->next=prev;
            prev=pal;
            pal=tmp;
        }

        slow->next=nullptr;
        
        ListNode* list1=head;
        ListNode* list2=prev;

        while(list1&&list2){
            if(list1->val!=list2->val){
                return false;
            }

            list1=list1->next;
            list2=list2->next;
        }

        return true;
    }
};
