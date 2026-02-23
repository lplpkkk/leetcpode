class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len=s.length();
        if (len< (1<<k)+k-1){
            return false;
        }

        unordered_set<int> seen;
        int num=0;
        int mask=(1<<k)-1;

        for(int i=0;i<len;i++){
            num=((num<<1)&mask)|(s[i]-'0');
            if(i>=k-1){
                seen.insert(num);
            }
            if(seen.size()>=(1<<k)){
                return true;
            }
        }
        return false;
    }
};
