

int singleNumber(int* nums, int numsSize) {
    //chk every digit
    unsigned int i=0;
    unsigned int j=0;
    unsigned int ans=0;

    for(i=0;i<32;i++){
        unsigned int sum=0;
        for(j=0;j<numsSize;j++){
            //sum+=(unsignednums[j]&BIT(i);
            sum+=(nums[j]>>i)&0x1;
        }

        if(sum%3){
            ans|=(1u<<i);    
        }
    }    

    return (int)ans;
}
