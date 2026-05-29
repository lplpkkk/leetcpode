class Solution {
public:
    int get_sum(int val){
        int tmp=val;
        int ans=0;

        while(tmp){
            ans+=(tmp%10);
            tmp/=10;    
        }

        return ans;
    }

    int minElement(vector<int>& nums) {
        int min=INT_MAX;
        for(auto& n:nums){
            int tmp_min=get_sum(n);
            if(tmp_min<min){
                min=tmp_min;
            }
        }    
        return min;
    }
};
