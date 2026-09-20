class Solution {
public:
    vector<int> palin;
    int ans=0;

    bool chk(string cand){
        int len=cand.length();
        int l=0,r=len-1;
        
        while(l<r){
            if(cand[l]!=cand[r]) return false;
            l++;r--;
        }
        return true;
    }

    int maxProduct(string s) {
        int n=s.size();

        for(int i=0;i<(1<<n);i++){
            string tmp;
            for(int j=0;j<12;j++){
                
                if(i&(1<<j)){
                    tmp+=s[j];
                }
            }
            if(chk(tmp)){
                palin.push_back(i);
            }
        } 

        int palin_len=palin.size();

        for(int i=0;i<palin_len;i++){
            for(int j=0;j<palin_len;j++){
                if(i!=j){
                    if((palin[i]&palin[j])==0){
                        int a_len=__builtin_popcount(palin[i]);
                        int b_len=__builtin_popcount(palin[j]);
                        ans=max(ans,a_len*b_len);          
                    }
                }
            }
        }

        return ans;
    }
};
