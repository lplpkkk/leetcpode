class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX;
        int ans=0;

        for(int price: prices){
            min_price=min(price,min_price);
            ans=max(ans,price-min_price);    
        }

        return ans;
    }
};
