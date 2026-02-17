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
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    //use a while loop to get he len
    //len/k is the num of groups
    //if groups < len, split len group and padding    

    struct ListNode* tmp=head;
    int len=0;
    while(tmp){
        len++;
        tmp=tmp->next;
    }

    struct ListNode** ans=malloc(k*sizeof(struct ListNode*));
    *returnSize=k;

    int base_len=len/k;
    int rem=len%k;

    tmp=head;

    for(int i=0;i<k;i++){
        ans[i]=tmp;

        int cur_part=base_len+(rem>0?1:0);
        if(rem) rem--;

        for(int j=0;j<cur_part-1;j++){
            if(tmp){
                tmp=tmp->next;
            }
        }

        if(tmp){
            struct ListNode* next_node=tmp->next;
            tmp->next=NULL;
            tmp=next_node;
        }
    }

    return ans;
}
