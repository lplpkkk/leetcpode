class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=0;
        
       for(int bit=0;bit<30;bit++){
            vector<int> tmp;

            for(int n:nums){
              if((n&(1<<bit))==0){
                continue;
              }

              auto it=lower_bound(tmp.begin(),tmp.end(),n);
              
              if(it==tmp.end()){
                tmp.push_back(n);
              }else{
                *it=n;
              }

            }

            ans=max(ans,(int)tmp.size());
       }

       return ans;
    }
};
