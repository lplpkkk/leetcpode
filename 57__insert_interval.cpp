class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int len=intervals.size();
        int i=0;

        //push all left part
        while(i<len && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i+=1;
        }

        //push all overlap part
        while(i<len && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0], intervals[i][0]);
            newInterval[1]=max(newInterval[1], intervals[i][1]);
            i+=1;
        }
        ans.push_back(newInterval);

        //push all right part     
        while(i<len && intervals[i][0]>newInterval[1]){
            ans.push_back(intervals[i]);
            i+=1;
        }

        return ans;
    }
};
