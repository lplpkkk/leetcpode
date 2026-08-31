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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        ListNode* prev=nullptr;
        int idx=0;//start from head

        while(head){

            if(prev!=nullptr){
                if(head->val>prev->val){
                    //try max critial
                    if(head->next){
                        if(head->next->val<head->val){
                            critical.push_back(idx);
                        }
                    }
                }else if (head->val < prev->val){
                    //try min critical
                    if(head->next){
                        if(head->next->val>head->val){
                            critical.push_back(idx);
                        }
                    }
                }
            }

            idx++;
            prev=head;
            head=head->next;
        }

        if(critical.size()<2){
            return {-1,-1};
        }     

        int dist=INT_MAX;

        for(int i=1;i<critical.size();i++){
            dist=min(dist,critical[i]-critical[i-1]);    
        }

        return {dist,(critical[critical.size()-1]-critical[0])};
    }
};
