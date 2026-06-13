class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for(auto& s:words){
            int n=s.length();
            long long sum=0;

            for(char c:s){
                sum+=weights[c-'a'];
            }
            sum%=26;

            ans.push_back('z'-sum);
        }    

        return ans;
    }
};
