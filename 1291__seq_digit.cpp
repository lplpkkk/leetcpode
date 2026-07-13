/*
class Solution {
public:

    int gen_cand(int first_digit, int lim){
        int cand=0;
            
        for(int j=0;j<=lim;j++){
            cand=cand+first_digit;
            first_digit++;
            cand*=10;
        }

        return cand;
    }

    vector<int> sequentialDigits(int low, int high) {
        int start=to_string(low).digit();
        int stop=to_string(high).digit();
        vector<int> ans;
        

        for(int i=start;i<=stop;i++){
            //compose candidate
            int first_digit=1;
            int cand=gen_cand(first_digit,i);          

            while(cand>=low&&cand<=high){
                if(first_digit<10){
                    cand=gen_cand(first_digit,i);
                }
                if(cand>=low&&cand<=high){
                    and.push_back(cand);
                }
                first_digit++;
            }
        }

        return ans;
    }
};
*/


class Solution {
public:
    int gen_cand(int first_digit, int len) {
        int cand = 0;

        for (int j = 0; j < len; j++) {
            cand = cand * 10 + first_digit;
            first_digit++;
        }

        return cand;
    }

    vector<int> sequentialDigits(int low, int high) {
        int start = to_string(low).size();
        int stop = to_string(high).size();

        vector<int> ans;

        for (int len = start; len <= stop; len++) {
            for(int first_digit=1;first_digit+len-1<=9;first_digit++){
                int cand=gen_cand(first_digit,len);
                if(cand>=low&&cand<=high){
                    ans.push_back(cand);
                }
            }
        }

        return ans;
    }
};
