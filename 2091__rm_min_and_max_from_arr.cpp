class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_idx=-1, min_val=INT_MAX;
        int max_idx=-1, max_val=INT_MIN;
        int len=nums.size();

        for(int i=0;i<len;i++){
            int n=nums[i];

            if(n>max_val){
                max_val=n;
                max_idx=i;
            }
            
            if(n<min_val){
                min_val=n;
                min_idx=i;
            }
        }

        //candidate=> 2 separate from front and back,
        //            1 front (merge)
        //            1 back (merge)

        int front_idx, back_idx;

        if(min_idx<max_idx){
            front_idx=min_idx;
            back_idx=max_idx;
        }else{
            front_idx=max_idx;
            back_idx=min_idx;
        }

        int ans=front_idx+1+(len-back_idx);//2 separte
        ans=min(ans,back_idx+1);//1 front
        ans=min(ans,len-front_idx);//1 back

        return ans;
    }
};
