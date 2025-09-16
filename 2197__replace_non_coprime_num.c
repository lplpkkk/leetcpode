/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int gcd(int a,int b){
    while(b!=0){
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}


long long lcm(int a, int b){
    if(a==0||b==0) return 0;

    return (long long)a*b/gcd(a,b);
}


int* replaceNonCoprimes(int* nums, int numsSize, int* returnSize) {
    if(numsSize==0){
        *returnSize=0;
        return NULL;
    } 

    int top=-1;
    int* stack=malloc(sizeof(int)*numsSize);

    for(int i=0;i<numsSize;i++){
        int cur=nums[i];
        while(top>=0 && gcd(stack[top],cur)!=1){
            long long tmp_lcm=lcm(stack[top],cur);
            if(tmp_lcm>INT_MAX){
                //overflow
                break;
            }
            top--;
            cur=(int)tmp_lcm;
        }

        top++;
        stack[top]=cur;
    }

    *returnSize=top+1;
    
    return  stack;
}
