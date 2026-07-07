class Solution {
public:
    long long sumAndMultiply(int n) {
        string s;
        string n2s=to_string(n);
        long long sum=0;

        for(char c:n2s){
            if(c!='0'){
                sum+=(c-'0');
                s.push_back(c);        
            }
        }

        if(s.empty()) return 0;

        return stoll(s)*sum;    
    }
};
