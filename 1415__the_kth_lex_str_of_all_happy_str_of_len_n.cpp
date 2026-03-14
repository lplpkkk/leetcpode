class Solution {
public:
    string getHappyString(int n, int k) {
        int total=3*(1<<(n-1));
        if(k>total) return "";

        string res="";
        vector<char> letters={'a','b','c'};

        int grp_size=1<<(n-1);
        int idx=(k-1)/grp_size;
        res+=letters[idx];
        k=(k-1)%grp_size+1;

        for(int i=1;i<n;i++){
            grp_size>>=1;
            vector<char> next_letter;
            for(char c:letters){
                if(c!=res.back()){
                    next_letter.push_back(c);
                }
            }
            
            int next_idx=(k-1)/grp_size;
            res+=next_letter[next_idx];
            k=(k-1)%grp_size+1;
            
        }
        return res;
    }
};
