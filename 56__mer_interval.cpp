class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return {};
        }

        vector<vector<int>> res;

        //sort
        sort(intervals.begin(),intervals.end());

        res.push_back(intervals[0]);

        //for loop intervals, check non-overlap then push 
        for(int i=1;i<intervals.size();i++){
            vector<int>& last=res.back();

            if(intervals[i][0]<=last[1]){
                last[1]=max(intervals[i][1],last[1]);
            }else{
                res.push_back(intervals[i]);
            }
            
        }

        return res;
    }
};
