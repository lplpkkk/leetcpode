class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal=0;
        int ans=0;

        for(char c: s){
            if(c==')'){
                bal-=1;
            }else{
                bal+=1;
            }
            
            if(bal<0){
                ans+=1;
                bal=0;
            }
        }

        return (ans+bal);
    }
};
