class Solution {

public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> bucket(1e5+1,0);
        int maxv=0;

        for(auto& cost:costs){
            bucket[cost]+=1;    
            maxv=max(maxv,cost);
        }

        int ans=0;
        for(int i=0;i<=maxv;i++){
            if(coins<i){
                return ans;
            }else{
                while(bucket[i]>0 && coins>=i){
                    coins-=i;
                    ans+=1;
                    bucket[i]-=1;
                }    
            }
        }

        return ans;
    }
};
