class Solution {
public:
    vector<vector<int>> combine(int n, int k) {      
        vector<vector<int>> res;
        vector<int> cur;
        bt(1,n,k,cur,res);
        return res;
    }
private:
    void bt(int start, int end, int k, vector<int>& cur, vector<vector<int>>& res){
        if (cur.size()==k){
            res.push_back(cur);
            return;
        }

        for(int i=start;i<=end; i++){
            cur.push_back(i);
            bt(i+1,end,k,cur,res);
            cur.pop_back();
        }

        return;
    }

};
