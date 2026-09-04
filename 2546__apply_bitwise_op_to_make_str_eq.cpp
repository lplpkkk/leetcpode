class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        bool s_has1=false;
        bool tar_has1=false;

        for(char c:s){
            if(c=='1'){
                s_has1=true;
            }
        }    

        for(char c:target){
            if(c=='1'){
                tar_has1=true;
            }
        }

        return (s_has1==tar_has1);
    }
};
