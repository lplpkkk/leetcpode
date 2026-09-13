class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string> tmp;

        for(int n: nums){
            tmp.push_back(to_string(n));
        }

        sort(tmp.begin(),tmp.end(),
        [](const string& a, const string&b){
            return a+b>b+a;
        });

        if(tmp[0]=="0") return "0";

        string ans;

        for(auto& s:tmp){
            ans+=s;
        }

        return ans;

    }
};
