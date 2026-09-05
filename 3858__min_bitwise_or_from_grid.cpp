class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int must_zero=0;
        int ans=0;

        for(int i=16;i>=0;i--){
            int try_zero=must_zero|(1<<i);
            bool can_zero=true;

            for(auto& row: grid){
                bool found=false;

                for(auto& r:row){
                    if((r&try_zero)==0){
                        //this bit is possible
                        found=true;
                        break;
                    }
                }

                if(!found){
                    can_zero=false;
                    break;
                }
            }

            if(can_zero){
                must_zero=try_zero;
            }else{
                ans|=(1<<i);
            }
        }

        return ans;
    }
};
