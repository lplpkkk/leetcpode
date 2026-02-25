class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), [](int a,int b){
            int cnt_a=__builtin_popcount(a);
            int cnt_b=__builtin_popcount(b);

            if(cnt_a!=cnt_b){
                return cnt_a<cnt_b;
            }
            
            return a<b;
        });
        return arr;
    }
};
