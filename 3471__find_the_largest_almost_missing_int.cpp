class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans=-1;
        int appear[51]={0};
        
        for(int i=0;i<=nums.size()-k;i++){
            bool seen[51]={false};

            for(int j=i;j<i+k;j++){
                seen[nums[j]]=true;
            }
            
            for(int j=0;j<=50;j++){
                if(seen[j]){
                    appear[j]++;
                }
            }
        }

        for(int i=0;i<=50;i++){
            if(appear[i]==1){
                ans=max(ans,i);
            }
        }

        return ans;
    }
};
