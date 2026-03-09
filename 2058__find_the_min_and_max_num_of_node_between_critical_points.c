/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    //traverse from 1 to end, get the local max or min, record:
    //overall cnt <- less than 2 return [-1,-1]
    //local_min_dist <- update when we get new local max/min
    //local_max_dist will be the last idx-the first idx
    //first_idx
    int* ans=malloc(sizeof(int)*2);
    *returnSize=2;
    ans[0]=-1;ans[1]=-1;

    if (head==NULL || head->next==NULL || head->next->next==NULL){
        return ans;
    }

    struct ListNode* cur=head->next;
    struct ListNode* prev=head;
    int cnt=1;
    int local_min_dist=INT_MAX;
    int first_idx=-1;
    int prev_idx=-1;
    int cand_idx=-1;

    while(cur->next){
        //local max/min
        if(prev->val<cur->val && cur->val>cur->next->val
        ||prev->val>cur->val && cur->val<cur->next->val){\

            if(first_idx==-1){
                first_idx=cnt;
            }else{
                int dist=cnt-prev_idx;
                if(dist<local_min_dist){
                    local_min_dist=dist;
                }
            }
            prev_idx=cnt;
        }

        cnt+=1;
        prev=cur;
        cur=cur->next;
    }

    //handle fewer than 2 case
    if(local_min_dist!=INT_MAX){
        ans[0]=local_min_dist;ans[1]=prev_idx-first_idx;
    }

    return ans;
}
