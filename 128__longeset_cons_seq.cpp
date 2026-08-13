class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exist(nums.begin(),nums.end());
        int max_val=0;

        for(int n:exist){
            int len=1;

            if(!exist.count(n-1)){
                int cur=n;
                
                while(exist.count(cur+1)){
                    cur++;
                    len++;
                }
                
            }
            
            max_val=max(max_val,len);
        }

        return max_val;
    }
};
