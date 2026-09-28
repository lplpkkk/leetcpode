class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> sel;
        int cnt=0;
        
        for(auto& cand:intervals){
            //check if overlap
            bool overlap=false;
            for(int i=0;i<sel.size();i++){
                //candidate lower bound
                if(cand[0]>=sel[i][0]&& cand[0]<sel[i][1]){
                    //choose lower end
                    cnt++;
                    overlap=true;

                    if(cand[1]<sel[i][1]){
                        sel[i]=cand;
                    }
                }
            }
            if(!overlap) sel.push_back(cand);
        }

        return cnt;
    }
};
