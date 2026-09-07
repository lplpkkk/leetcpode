
/*
class Solution {
public:
    vector<vector<int>> cand(32);//this is the pool for 
    long long maxProduct(vector<int>& nums) {
        //classify to cand
        for(int n:nums){
            for(int bit=0;bit<32;bit++){
                if((n&(1<<bit))!=0){
                    cand[bit].push_back(n);
                }
            }
        }

        int ans=0;

        //for loop and try
        for(int n:nums){
            //remove forbidden bit
            vecotr<int> ok_bit(32,1);
            int tmp=n;
            int offset=0;

            while(tmp){
                if((n&1)==1) ok_bit(offset)=0;
                offset++;    
                tmp>>=1;
            }

            //try combination with exclusive bits
            for(int i=0;i<32;i++){
                if(ok_bit[i]==1){
                    for(int j=0;j<cand[i].size();j++){
                        ans=max(ans,n*cand[i][j]);
                    }
                }
            }
            
        }

        return ans;
    }
        
}
*/


class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int max_n=*max_element(nums.begin(),nums.end());
        int msb=log2(max_n),max_mask=(1<<(msb+1))-1;

        vector<int> dp(max_mask+1);

        for(int x:nums){
            dp[x]=x;
        }

        for(int b=0;b<=msb;b++){
            for(int mask=0;mask<max_mask;mask++){
                if(mask&(1<<b)){
                    dp[mask]=max(dp[mask],dp[mask^(1<<b)]);
                }
            }
        }

        long long ans=0;
        for(int n:nums){
            ans=max(ans,1LL*n*dp[max_mask^n]);
        }

        return ans;
    }
};
