class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows==1) return encodedText;

        int n=encodedText.length();
        int cols=n/rows;
        string res="";

        for(int c=0;c<cols;c++){
            int cur_r=0;
            int cur_c=c;
            
            while(cur_r<rows&&cur_c<cols){
                res+= encodedText[cur_r*cols+cur_c];
                cur_r++;
                cur_c++;
            }
        }

        while(!res.empty()&&res.back()==' '){
            res.pop_back();
        }

        return res;
        
    }
};
