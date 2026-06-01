class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int total=0;

        while((n-1)>=0){
            if(n-1>=2){
                total+=(cost[n-1]+cost[n-2]);        
                n-=3;
            }else{
                total+=cost[n-1];
                n-=1;
            }
        }
        
        return total;
    }
};
