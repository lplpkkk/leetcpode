/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int numComponents(struct ListNode* head, int* nums, int numsSize) {
    int ans=0;
    bool set[10001]={0};

    for(int i=0;i<numsSize;i++){
        set[nums[i]]=1;
    }

    while(head){
        if((set[head->val]==1)&&((!head->next)||(!set[head->next->val]))){
            ans++;
        }
        head=head->next;
    }
    return ans;
}
