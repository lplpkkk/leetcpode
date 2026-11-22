class Solution {
public:
    bool checkString(string s) {
        //find the first b
        int first_b_idx=0;
        
        for(;first_b_idx<s.length();first_b_idx++){
            if(s[first_b_idx]=='b') break;
        }
        
        for(int i=first_b_idx;i<s.length();i++){
            if(s[i]=='a') return false;
        }

        return true;
    }
};
