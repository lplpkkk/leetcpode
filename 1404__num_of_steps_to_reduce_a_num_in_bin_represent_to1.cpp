class Solution {
public:
    int numSteps(string s) {
        int len=s.length();
        int steps=0;
        int carry=0;

        for(int i=len-1;i>0;i--){
            int this_d=s[i]-'0'+carry;
            if(this_d&1){//odd
                carry=1;
                steps+=2;
            }else{
                steps+=1;
            }
        }
        return steps+carry;
    }
};
