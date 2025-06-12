

int findDuplicate(int* nums, int numsSize) {

    //check if there is cycle
    int slow=nums[0];//1,3,2
    int fast=nums[nums[0]];//3,4,4

    while(fast!=slow){
        slow=nums[slow];
        fast=nums[nums[fast]];
    }

    slow=0;
    while(fast!=slow){
        slow=nums[slow];
        fast=nums[fast];
    }

    return slow;
}
