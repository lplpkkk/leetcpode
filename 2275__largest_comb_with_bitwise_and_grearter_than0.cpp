
/*
class Solution {
public:
    int largestCombination(vector<int>& cand) {
        if(cand.size()==0) return 0;

        int ans=1;
        int l=0;
        int r=0;
        int tmp=-1; //0xff...ff
        vector<int> record(cand.size());

        while(l<r&&r<cand.size()){
            if((tmp&cand[r])>0){
                r++;
                tmp&=cand[r];
                record[l]=tmp;
            }else{
                //??? want to recover what l did
                tmp=record[l-1];
                l++
            }
            ans=max(ans,r-l+1);
        }

        return ans;

    }
};

 stuck here !! and I misunderstand this question...
 NO NEED TO BE CONTIGUOUS

*/

class Solution {
public:
    int largestCombination(vector<int>& cand) {
        int ans=0;

        for(int i=0;i<32;i++){
            int cnt=0;

            for(int n:cand){
                if( n&(1<<i) ){
                    cnt++;
                }
            }

            ans=max(ans,cnt);
        }

        return ans;
    }
};
