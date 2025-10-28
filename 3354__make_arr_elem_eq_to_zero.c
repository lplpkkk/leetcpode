
/*
int dfs(int* nums, int numsSize, int idx, int cnt, int dir){
    if((idx>numsSize-1)||(idx<0)){
        return cnt;
    }

    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    if(sum==0){
        cnt++;
    }

    if(dir==0){
        //left
        if(num[idx]==0){
            return dfs(nums,numsSize,idx-1,cnt,0);
        }else{
            nums[idx]--;
            return dfs(nums,numsSize,idx+1,cnt,1);
        }
            
    }else{
        //right
        if(num[idx]==0){
            return dfs(nums,numsSize,idx+1,cnt,1);
        }else{
            nums[idx]--;
            return dfs(nums,numsSize,idx-1,cnt,0);
        }
    }
    
}

int countValidSelections(int* nums, int numsSize) {
    int ans=0;
    int* tmp=malloc(sizeof(int)*numsSize);
    

    for(int i=0;i<numsSize;i++){
        if(nums[i]==0){
            memcpy(tmp,nums,sizeof(int)*numsSize);
            ans+=dfs(tmp,numsSize,i,0,0);
            ans+=dfs(tmp,numsSize,i,0,1);
        }
        
    }
    return ans;    
}'
*/
int countValidSelections(int* nums, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += nums[i];

    int left = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (left == total - left)  // 左右和相等
                ans += 2;
            else if (abs(left - (total - left)) == 1)
                ans += 1;
        }
        left += nums[i];
    }
    return ans;
}
