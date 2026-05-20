class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int len=A.size();
        vector<int> ans;
        vector<int> freq(len+1,0);
        int common=0;

        for(int i=0;i<len;i++){
            freq[A[i]]++;
            if(freq[A[i]]==2){
                common++;
            }


            freq[B[i]]++;
            if(freq[B[i]]==2){
                common++;
            }

            ans.push_back(common);
        }

        return ans;
    }
};
