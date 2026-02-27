class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {

        int len=heights.size();
        if(len==0){
            return {};
        }

        int max_h=0;
        vector<int> ans;

        for(int i=len-1;i>=0;i--){
            if(heights[i]>max_h){
                ans.push_back(i);
                max_h=heights[i];
            }
        }
  
        reverse(ans.begin(),ans.end());      
        return ans;
    }
};
