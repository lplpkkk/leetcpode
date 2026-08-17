class Solution {
public:
    int minimumSize(vector<int>& nums, int maxop) {
        int start=1,end=*max_element(nums.begin(),nums.end());
        int minp=end;

        while(start<=end){
            int p=start+(end-start)/2;
            if(can(nums,maxop,p)){
                minp=p,end=p-1;
            }else{
                start=p+1;
            }
        }

        return minp;
    }

    bool can(vector<int>& nums, int maxop, int p){
        long long req=0;
        for(int n:nums){
            int x=n/p;
            if(n%p==0){
                x--;
            }

            req+=x;
        }

        return req<=(long long)maxop;
    }
};
