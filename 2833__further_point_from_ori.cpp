class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l_num=0;
        int r_num=0;
        int arb_num=0;

        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L'){
                l_num++;
            }else if(moves[i]=='R'){
                r_num++;
            }else{
                arb_num++;
            }
        }
        
        int larger_num=(l_num>r_num)?l_num:r_num;
        int smaller_num=(l_num>r_num)?r_num:l_num;
        return larger_num-smaller_num+arb_num;
    }
};
